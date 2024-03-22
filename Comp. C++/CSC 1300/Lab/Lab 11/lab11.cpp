/*
	Title: Lab11.cpp
	Name: Ethan Newman
	Date: 4/4/2019
	Purpose: Dynamic Allocation and Array of Pointers

*/

#include<iostream>

using namespace std;

int libSize = 4;

int main()
{
	int** numBooksArray;
	int numGenre = 0;
	int numMax = 0;
	
	numBooksArray = new int* [libSize];
	
	cout << "\nHow many genres of books are there: ";
	cin >> numGenre;
	
	for (int i = 0; i < libSize; i++)
	{
	
		numBooksArray[i] = new int [numGenre];
		
			for (int x = 0; x < numGenre; x++)
			{
				cout <<"\nHow many books are there in each genre? " << endl;
				cout << "\n LIBRARY " << i+1 << " GENRE " << x+1 << ": ";
				cin >> numBooksArray[i][x];
				
					if (numBooksArray[i][x] > numMax)
					{
						numMax = numBooksArray[i][x];
						
					
					}
			}
	}
	
	for (int j = 0; j < libSize; j++)
	{
		for (int k = 0; k < libSize; k++)
		{
			if (numBooksArray[j][k] == numMax)
						{
							cout << "\nLIBRARY " << j+1 << " has the largest number of books in GENRE " << k+1 << " which contains " << numMax << " books!";
						
						}
		}
	
	
	}
	delete [] numBooksArray;
	
	return 0;
}