#include "graphlist.h"
#include "graphmatrix.h"
#include "stack.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include <string>

using namespace std;

void DFS(GraphMatrix*, int, int);

int main()
{
	char filename[100];
	int numV = 0;
	int v1, v2;
	
	cout << "What is the name of your file?\n";
	cin.getline(filename, 100);
	
	ifstream inFile;
	inFile.open(filename);

	inFile >> numV;
	inFile >> v1;
	
	int source = v1;

	GraphList* myList = new GraphList(numV);
	GraphMatrix* myMatrix = new GraphMatrix(numV);
		
	while(!inFile.eof())
	{
		inFile >> v2;
		
		myMatrix->addEdge(v1, v2);
		myList->addEdge(v1, v2);
		
		inFile >> v1;
	}
	
	cout << "\n\nPrint Matrix List." << endl;
	myMatrix->printGraph();
	
	cout << "\nPrinting Adjacency List." << endl;
	myList->printGraph();
	
	cout << "\nPrinting Depth-First Search." << endl;
	DFS(myMatrix, source, numV);
	
	delete[] myMatrix;
	delete[] myList;
	
	return 0;
}
	
void DFS(GraphMatrix* temp, int s, int numV)
{
	Stack<int> myStack;
	vector<bool> visited(numV, false);
	int top;
	
	myStack.push(s);
		
	while (!myStack.isEmpty())
	{
		myStack.peek(top);
		
		if (!visited[top])
		{
			cout << top << " ";
			visited[top] = true;
		}
		
		bool startOver = false;
		
		for (int i = 0; i < numV || startOver == true; i++)
		{
			if (startOver == true)
			{
				startOver = false;
				i = 0;
			}
			
			if(temp->isThereAnEdge(top, i) && !visited[i])
			{
				myStack.push(i);
				visited[i] = true;
				cout << i << " ";
				top = i;
				startOver = true;
			}
		/*	else if(visited[i])
			{
				myStack.pop(i);
				
				if(temp->isThereAnEdge(top, i) && !visited[i])
				{
					myStack.push(i);
					visited[i] = true;
					cout << i << " ";
				}
			}*/
		}
		myStack.pop(top);
	}
}
			
		
		
		
	
	
	
	