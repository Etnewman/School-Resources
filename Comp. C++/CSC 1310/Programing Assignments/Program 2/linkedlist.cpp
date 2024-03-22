		#include "linkedlist.h"
		#include "creature.h"
		#include <iostream>
		
		
		using namespace std;
		
		template <typename L>
		LinkedList<L>::LinkedList()
		{
			head = NULL;
			tail = NULL;
		}
		
		template <typename L>
		int LinkedList<L>::getLength()
		{
			int counter = 0;
			ListNode* nodePtr;
			
			nodePtr = head;
			
			while (nodePtr != tail)
			{
				counter++;
				nodePtr = nodePtr->next;
				if (nodePtr == tail)
				{
					counter++;
				}
			}
			return counter;
		}
		
		template <typename L>
		L LinkedList<L>::getNodeValue(L pos)
		{
			ListNode *nodePtr;
			if (!head)
			{
				return;
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
					currPos++
					nodePtr = nodePtr->next;
				}
			}
			return;
		}
			
		
		template <typename L>
		void LinkedList<L>::appendNode(L temp)
		{
			ListNode *newNode;
			
			newNode = new ListNode;
			newNode->value = temp
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
			}
		}
		
		template <typename L>
		LinkedList<L>::deleteNode(L num)
		{
			ListNode *nodePtr*;
			ListNode *prevNode;
			
			if (!head)
			{
				return;
			}
			
			if (head->value == num)
			{
				nodePtr = head->next;
				delete head;
				head = nodePtr;
			}
			else{
				nodePtr = head;
				
				while (nodePtr != NULL && nodePtr->value != num)
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