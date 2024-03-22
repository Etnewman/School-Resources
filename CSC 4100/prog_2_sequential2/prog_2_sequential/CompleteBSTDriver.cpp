#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>

#include "BinarySearchTree.h"
using CSC1310::BinarySearchTree;
#include "BinaryTreeIterator.h"
using CSC1310::BinaryTreeIterator;
#include "ListArray.h"
using CSC1310::ListArray;
#include "ListArrayIterator.h"
using CSC1310::ListArrayIterator;

#include "Permutation.h"
using CSC1310::Permutation;
#include "Random.h"
using CSC1310::Random;

#include <pthread.h>
#include "CD.h"

#include <iostream>
using namespace std;

int BUFFER_SIZE = 1;
int NUM_PRODUCERS = 10;
int NUM_CONSUMERS = 10;
int NUM_TREES = 10000;
int ERROR_RATE = 10;

CD*** buffer;
int buffer_count = 0;
int producer_index = 0;
int consumer_index = 0;

int num_trees_p = 0;
int num_trees_c = 0;

pthread_cond_t empty, full;
pthread_mutex_t mutex;

void *producer_seq(long *producer_args);
void *consumer_seq(int *consumer_args);
void deleteCDs(ListArray<CD>* list);
void put(CD** cds_array);
CD** get();

int main()
{
	pthread_t producer[NUM_PRODUCERS];
	pthread_t consumer[NUM_CONSUMERS];
	buffer = new CD**[BUFFER_SIZE];
	
	time_t start, end;
	Random* rand = Random::getRandom();
	   
   //the unsorted ListArray of cds
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   cout << num_items << endl;
   cout << "based on the number of items, the min height should be: " << endl;
   int expected_height = ceil(log2(num_items + 1));
   cout << expected_height << endl;
   cout << endl;
   
   long producer_args[2];
   producer_args[0] = (long) cds;
   producer_args[1] = (long) rand;
   
   int consumer_args[2];
   consumer_args[0] = num_items;
   consumer_args[1] = expected_height;
  
   start = time(NULL);

//sequential solution: process one tree at a time
	/*for (int i = 1; i <= NUM_TREES; i++)
	{
	    CD** cd_array = producer_seq(cds, rand);
		consumer_seq(cd_array, num_items, expected_height);
	}*/
   
    end = time(NULL);
   printf("sequential: %ds\n", (int)(end - start)); 
	
	//Threaded Solution, start time
	
	start = time(NULL);
	
	//Create Threads
	
	for (int i = 0; NUM_PRODUCERS; i++)
	{
		cout << "IN THREAD LOOP P";
		pthread_create(&producer[i], NULL, producer_seq, (void*)&producer_args);
	}
	
	for (int i = 0; NUM_CONSUMERS; i++)
	{
		cout << "IN THREAD LOOP C";
		pthread_create(&consumer[i], NULL, consumer_seq, (void*)&consumer_args);
	}
	
	//Join both threads here
	
	for (int i = 0; NUM_PRODUCERS; i++)
	{
		pthread_join(producer[i], NULL);
	}
	
	for (int i =0; NUM_CONSUMERS; i++)
	{
		pthread_join(consumer[i], NULL);
	}
	
	end = time(NULL);
	
   deleteCDs(cds);
   delete cds;
   
   delete[] buffer;
   
   

   return 0;
}

void put(CD** cds_array)
{
	buffer[producer_index] = cds_array;
	producer_index = (producer_index + 1) % BUFFER_SIZE;
	buffer_count++;  //buffer fills up
}

CD** get()
{
	CD** cds_array = buffer[consumer_index];
	consumer_index = (consumer_index + 1) % BUFFER_SIZE;
	buffer_count--;  //buffer empties out
	return cds_array;
}

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }

   delete iter;
}

void *producer_seq(long *p_args)
{
//1.  get an array with the cds in a random order
		ListArray<CD>* cds = (ListArray<CD>*) &p_args[0];
		Random* rand = (Random*) &p_args[1];
		
	    int num_items = cds->size();
		Permutation* p = new Permutation(num_items, num_items, rand);
		p->basicInit();
		
		CD** permute_cds = new CD*[num_items];
		int count = 0;
		while(p->hasNext())
		{
			//lock
			pthread_mutex_lock(&mutex);
			while(buffer_count==BUFFER_SIZE)
			{
				cout << "Producer Sleeping...";
				pthread_cond_wait(&full, &mutex);
			}
			put(permute_cds);
			pthread_cond_signal(&full);
			
			int i = p->next();
			permute_cds[count] = cds->get(i);
			
			pthread_mutex_unlock(&mutex);
			//unlock
			count++;
		}
		delete p;

//2.  insert the cds in array order (different each time) into BST
		BinarySearchTree<CD>* bst = new BinarySearchTree<CD>(&CD::compare_items, &CD::compare_keys);
		for (int i = 0; i < num_items; i++)
		{
			CD* cd = permute_cds[i];
			bst->insert(cd);
		}
		delete[] permute_cds;
  
//3.  create a complete binary search tree
		BinarySearchTree<CD>* complete_bst = bst->minimizeComplete();
		CD** cds_array = new CD*[num_items];
		BinaryTreeIterator<CD>* complete_iter = complete_bst->iterator();

//4.  place the cds into an array using a level order traversal
		//intentionally inserting an error in some cases using a post order traversal
		int traversal_error = rand->getRandomInt(1, NUM_TREES);
		if (traversal_error >= ERROR_RATE)
		{
			complete_iter->setLevelorder();
		}
		else
		{
			//wrong traversal, consumer should detect a height error
			//still will be sorted, however
			complete_iter->setPostorder();
		}
		count = 0;
		while(complete_iter->hasNext())
		{
			//lock
			pthread_mutex_lock(&mutex);
			while(buffer_count==BUFFER_SIZE)
			{
				cout << "Producer Sleeping...";
				pthread_cond_wait(&full, &mutex);
			}
			put(cds_array);
			pthread_cond_signal(&full);
			
			cds_array[count] = complete_iter->next();
			count++;
			
			pthread_mutex_unlock(&mutex);
			//unlock
		}
		delete bst;
		delete complete_iter;
		delete complete_bst;
		
//5.  return the array that is supposed to represent a complete binary tree
		return cds_array;
}

void *consumer_seq(int *c_args)
{
//1.  put the items in the provided array into a BST
//note that if the array represents a complete binary tree,
//this process will create a complete binary tree that is also a BST
		BinarySearchTree<CD>* bst = new BinarySearchTree<CD>(&CD::compare_items, &CD::compare_keys);
		for (int i = 0; i < c_args[0]; i++)
		{
			//lock
			pthread_mutex_lock(&mutex);
			while(buffer_count == 0)
			{
				cout << "Consumer Sleeping...";
				pthread_cond_wait(&empty, &mutex);
			}
			CD** cds_array = get();
			
			CD* cd = cds_array[i];
			bst->insert(cd);
			
			pthread_mutex_unlock(&mutex);
			//unlock
		}

//2.  verify that the items are in sorted order using an inorder traversal
		BinaryTreeIterator<CD>* bst_iter = bst->iterator();
		bst_iter->setInorder();  //this was omitted
		CD* first = bst_iter->next();
		bool sorted = true;
		while(bst_iter->hasNext())
		{
			//lock
			pthread_mutex_lock(&mutex);
			while(buffer_count == 0)
			{
				cout << "Consumer Sleeping...";
				pthread_cond_wait(&empty, &mutex);
			}
			CD** temp = get();
			
			CD* second = bst_iter->next();
			
			pthread_mutex_unlock(&mutex);
			//unlock
			if (CD::compare_items(first, second) >= 0)
			{
				sorted = false;
				break;
			}
			first = second;
		}
		delete bst_iter;

//3.  check that the BST is minimum height and balanced
//the randomly determined errors will fail the height test
		int h = bst->getHeight();
		bool bal = bst->isBalanced();
   
		if (!sorted || h != c_args[1] || !bal)
		{
			cout << "invalid complete binary tree" << endl;
		}
		else
		{
			//cout << "valid complete binary tree" << endl;
		}

		delete bst;
		delete[] cds_array;
}

	