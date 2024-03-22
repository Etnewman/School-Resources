#ifndef STACK_H
#define STACK_H
#include <iostream>

using namespace std;

template <typename S>
class Stack
{
private:

	struct StackNode
	{
		S value;
		StackNode *next;
	};
	
	StackNode *top;
	
public:

	Stack()
	{ top = NULL;}
	
	void push(S);
	void pop(S &);
	bool isEmpty();
};

template <typename S>
void Stack<S>::push(S temp)
{
	StackNode *newNode = NULL;
	
	newNode = new StackNode;
	newNode->value = temp;
	
	if (isEmpty())
	{
		top = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
}

template <typename S>
void Stack<S>::pop( S &item)
{
	StackNode *temp = NULL;
	
	if (isEmpty())
	{
		cout << "\nThe Stack is Empty.\n";
	}
	else
	{
		item = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}

template <typename S>
bool Stack<S>::isEmpty()
{
	bool temp;
	
	if (!top)
	{
		temp = true;
	}
	else
	{
		temp = false;
	}
	
	return temp;
}
#endif










