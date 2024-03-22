#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "creature.h"
#include <iostream>
#include <string>

using namespace std;

template <typename L>
class LinkedList
{
	private:
	
		struct ListNode
		{
			L value; 
			struct ListNode *next;
		};
		
		ListNode* head;
		ListNode* tail;
		int numNodes;
		
		public:
		
		LinkedList();

		~LinkedList();
		
		int getLength();
		
		L getNodeValue(int pos);
		
		void appendNode(L temp);
		
		void deleteNode(int num);
};

template <typename L>
LinkedList<L>::LinkedList()
{
	head = NULL;
	tail = NULL;
	numNodes = 0;
}
		
template <typename L>
int LinkedList<L>::getLength()
{
	return numNodes;
}
		
template <typename L>
L LinkedList<L>::getNodeValue(int pos)
{
	ListNode *nodePtr;

		if (pos == 0)
		{
			return head->value;
		}
		nodePtr = head;
		int currPos = 0;
		while (pos >= currPos && nodePtr != NULL)
		{
			if (pos == currPos)
			{
				return nodePtr->value;
			}
			currPos++;
			nodePtr = nodePtr->next;
		}
}
	
		
template <typename L>
void LinkedList<L>::appendNode(L temp)
{
	ListNode *newNode;
	
	newNode = new ListNode;
	newNode->value = temp;
	newNode->next = NULL;
	numNodes++;
	
	if (!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}	

template <typename L>
void LinkedList<L>::deleteNode(int num)
{
	ListNode *nodePtr;
	ListNode *prevNode;
	int index = 0;

	if (!head)
	{
		return;
	}
	
	
	if (index == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else{
		nodePtr = head;
		
		while (nodePtr != NULL && index != num)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
			index++;
		}
		
		if (nodePtr)
		{
			if (nodePtr == tail)
			{
				tail = prevNode;
			}
			prevNode->next = nodePtr->next;
			delete nodePtr;
		} 
	}
	numNodes--;
}

template <typename L>
LinkedList<L>::~LinkedList()
{
	ListNode *nodePtr;
	ListNode *nextPtr;
	
	nodePtr = head;

	while(nodePtr != NULL)
	{
		nextPtr = nodePtr->next;
		delete nodePtr;
		numNodes--;
		nodePtr = nextPtr;
	}
}

#endif


	