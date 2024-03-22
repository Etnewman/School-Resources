#include <iostream>
#include <fstream>
#include "graphlist.h"

using namespace std;

int main()
{
	int numV = 0;
	int v1 = 0;
	int v2 = 0;
	
	ifstream inFile;
	inFile.open("graph.txt");

	
	inFile >> numV;

	GraphList* myTable = new GraphList(numV);
	
	while(!inFile.eof())
	{
		inFile >> v1;
		inFile >> v2;
		
		myTable->addEdge(v1, v2);
	}
	cout << "\n\nAdjacency List...\n";
	
	myTable->printGraph();
	
	delete[] myTable;
	
	return 0;
}
		