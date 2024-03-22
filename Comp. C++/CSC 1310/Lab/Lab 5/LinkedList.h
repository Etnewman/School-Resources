#ifndef LinkedList_H
#define LinkedList_H

#include <string>

using namespace std;

class LinkedList
{
	private:
	
		struct ListNode
		{
			string value;
			struct ListNode *next;
		};
	
	ListNode* head;
	ListNode* tail;
	
	public:
	
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	
	~LinkedList();
	bool isEmpty();
	int getLength();
	string getNodeStr(int);
	void bubbleSort();
	void swap(int, int);
	void appendNode(string);
	void deleteNode(string);
	void displayList() const;
	
	//Instead of inserting a node into a certain spot so that it 
	//was sorted, I used my append function along with a sort function
	//to do the same thing.
};
#endif


