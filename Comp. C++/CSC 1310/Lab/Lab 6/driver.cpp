/*
	Name: Ethan Newman
	Assignment: Lab 6
	Date: 10/20/2019
	Instructor: April Crockett
*/
#include "stack.h"
#include<fstream>
#include<iostream>

int main()
{
	Stack<char> stack;
	char temp;
	char variable;
	
	ifstream inFile;
	inFile.open("file1.txt");
	if (inFile.good())
	{
		inFile.get(temp);
		while (!inFile.eof())
		{
			stack.push(temp);
			inFile.get(temp);
		}
	}
	
	ofstream outFile;
	outFile.open("file2.txt");
	
	while (!stack.isEmpty())
	{
		stack.pop(variable);
		outFile.put(variable);
	}
	return 0;
	
}
			