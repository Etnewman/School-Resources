#ifndef HEAP_H
#define HEAP_H
#include "Student.h"
#include <cmath>
#include <iostream>

class Heap
{
	private:
		
		Student* items;
		int heap_size;
		int capacity;
		
		void swap(Student* x, Student* y)
		{
			Student temp = *x;
			*x = *y;
			*y = temp;
		}
		
		int parent(int i)
		{ 
			return (i-1)/2; 
		}
		
		int left(int i)
		{ 
			return (2*i + 1); 
		}
		
		int right(int i)
		{ 
			return (2*i + 2); 
		}
		
		bool isLeaf(int nodeIndex)
		{
			return (left(nodeIndex) >= heap_size);
		}

		void heapRebuild(const int subTreeRootIndex);
		
	public:
	
		Heap(int);
		~Heap();
		
		bool isEmpty() const;
		
		int getNumberOfNodes() const;
		
		int getHeight() const;
		
		void insert(Student newData);
		
		Student remove();
		
};

//PRIVATE FUNCTIONS:

void Heap::heapRebuild(const int subTreeNodeIndex)
{
	if (!isLeaf(subTreeNodeIndex))
	{
		int leftCI = left(subTreeNodeIndex);
		int largerCI = leftCI;
		int rightCI = right(subTreeNodeIndex);
		
		if (rightCI < heap_size)
		{
			if (items[rightCI] > items[largerCI])
			{
				largerCI = rightCI;
			}
		}
		if (items[subTreeNodeIndex] < items[largerCI])
		{
			swap(&items[largerCI], &items[subTreeNodeIndex]);
			
			heapRebuild(largerCI);
		}
	}
}

//PUBLIC FUNTIONS:

Heap::Heap(int num)
{
	heap_size = 0;
	capacity = num;
	items = new Student[capacity];
}

Heap::~Heap()
{
	delete [] items;
}

bool Heap::isEmpty() const
{
	if (heap_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Heap::getHeight() const
{
	return ceil(log2(heap_size + 1));
}

int Heap::getNumberOfNodes() const
{
	return heap_size;
}

void Heap::insert(Student newData)
{
	
	items[heap_size] = newData;
	
	heap_size++;
	int i = heap_size - 1;
	
	while (i != 0 && items[parent(i)] < items[i])
	{
		swap(&items[i], &items[parent(i)]);
		i = parent(i);
	}
}

Student Heap::remove()
{
	Student temp;
	if (!isEmpty()) 
	{
		temp = items[0];
		items[0] = items[heap_size - 1];
		heap_size--;
		heapRebuild(0);
	}
	else
	{
		cout << "\nThe heap is empty so I can't remove any values.\n";
	}
	
	return temp;
}

#endif
	
	
	
	
	
	
	
	
	