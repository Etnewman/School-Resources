#include <iostream>
#include "LinkedList.h"
using namespace std;

bool LinkedList::isEmpty()
{
	if(!head)
		return true;
	else
		return false;
}

int LinkedList::getLength()
{
	int counter = 0;
	ListNode *nodePtr;
	
	nodePtr = head;
	
	while(nodePtr != tail)
	{
		counter++;
		nodePtr = nodePtr->next;
		if (nodePtr == tail)
			counter++;
	}
	return counter;
}

string LinkedList::getNodeStr(int pos)
{
	ListNode *nodePtr;
	if(!head)
	{
		return string();
	}
	else
	{
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
	return string();
}

void LinkedList::bubbleSort()
{
	for (int last = getLength()-1; last > 0; last--)
	{
		for (int i = 0; i < last; i++)
		{
			if(getNodeStr(i) > getNodeStr(i+1))
			{
				swap(i+1, i);
			}
		}
	}
}

void LinkedList::swap(int pos1, int pos2)
{
	ListNode *nodePtr1 = NULL;
	ListNode *nodePtr2 = NULL;
	string temp;
	
	nodePtr1 = head;

	int currPos = 0;
	while (nodePtr1 != NULL && pos1 != currPos)
	{
		nodePtr1 = nodePtr1->next;
		currPos++;
	}
	
	nodePtr2 = head;
	currPos = 0;
	
	while (nodePtr2 != NULL && pos2 != currPos)
	{
		nodePtr2 = nodePtr2->next;
		currPos++;
	}
	
	temp = nodePtr1->value;
	nodePtr1->value = nodePtr2->value;
	nodePtr2->value = temp;
}


void LinkedList::appendNode(string temp)
{
	ListNode *newNode;
	
	newNode = new ListNode;
	newNode->value = temp;
	newNode->next = NULL;
	
	if (!head)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
		bubbleSort(); //This is where I call my sort function after appending
	}
}

void LinkedList::deleteNode(string temp)
{
	ListNode *nodePtr;
	ListNode *prevNode;
	
	if (!head)
	{
		return;
	}

	if (head->value == temp)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;
		
		while (nodePtr != NULL && nodePtr->value != temp)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
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
}
	
void LinkedList::displayList() const
{
	ListNode *nodePtr;
	
	if(head !=NULL)
	{
		nodePtr = head;
		
		while(nodePtr)
		{
			cout << nodePtr->value << endl;
			nodePtr = nodePtr->next;
		}
	}
	else
		cout << "\nThere are no nodes in the list.\n\n";
}

LinkedList::~LinkedList()
{
	ListNode *nodePtr;
	ListNode *nextNode;
	
	nodePtr = head;
	
	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		
		delete nodePtr;
		
		nodePtr = nextNode;
	}
}
	
	
	
	
	
	
	
	
	
	
	
	