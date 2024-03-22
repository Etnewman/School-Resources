#ifndef GRAPHLIST_H
#define GRAPHLIST_H
#include <iostream>
#include <iomanip>
using namespace std;

class GraphList
{
	private:
		
		struct ListNode
		{
			int value;
			ListNode* next;
		};
		
		ListNode** headArray;
		int numVertices;
		int numEdges;
		
		public:
		GraphList(int);
		~GraphList();
		void addEdge(int, int);
		void printGraph();
};

GraphList::GraphList(int numV)
{
	this->numVertices = numV;
	this->numEdges = 0;
	headArray = new ListNode*[numV];
	
	for (int i = 0; i < numV; i++)
	{
		headArray[i] = NULL;
	}
	
}

GraphList::~GraphList()
{
	for (int i = 0; i < numVertices; i++)
	{
		delete headArray[i];
	}
}

void GraphList::addEdge(int v1, int v2)
{
	ListNode* newNode = new ListNode;
	
	newNode->value = v2;
	newNode->next = NULL;
	numEdges++;
	
	ListNode* nodePtr = headArray[v1];
	
	if (nodePtr == NULL)
	{
		headArray[v1] = newNode;
	}
	else
	{
		while (nodePtr->next != NULL)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
	}	
	//cout << "\nAdding edge from " << v1 << " to " << v2 << ".";
}

void GraphList::printGraph()
{
	for (int i = 0; i < numVertices; i++)
	{
		if (headArray[i] != NULL)
		{
			ListNode* entry = headArray[i];
			cout << i;
			
			while(entry->next != NULL)
			{
				cout << "----->" << entry->value;
				entry = entry->next;
			}
			
			cout << "----->" << entry->value << "----->NULL";
			cout << endl;
		}
		
		else
		{
			cout << i << "----->NULL" << endl;
		}
	}		
}

#endif
	
	