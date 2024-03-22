#include "Song.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

//LOOK!!  ENTER YOUR FUNCTION PROTOTYPES HERE
void bubbleSort(Song*, int);
void insertionSort(Song*, int);
void quickSort(Song*, int, int);
int partition(Song*, int, int);
int main()
{
	Song *mySongArray;
	mySongArray = new Song[150000];
	int numSongs = 0;
	float length;
	string temp;
	
	ofstream outFile;
	ifstream inFile;

	time_t start, end;
	char filename[50];
	cout << "\n\nWhat is the name of the file with songs? (example.txt)\n";
	cin >> filename;
	inFile.open(filename);
	
	if(!inFile)
	{
		cout << "\n\nSorry, I can't open the file songs.txt\n\n";
		exit(1);
	}
	
	while(getline(inFile, temp) && numSongs != 150000)
	{
		mySongArray[numSongs].setTitle(temp);
		getline(inFile, temp);
		mySongArray[numSongs].setArtist(temp);
		inFile >> length;
		inFile.ignore();
		mySongArray[numSongs].setLength(length);
		numSongs++;
	}
	cout << "\n\nYou have created " << numSongs << " Song objects.\n\n";
	
	
	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   
	
	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	insertionSort(mySongArray, numSongs);
	
	
	
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE
	bubbleSort(mySongArray, numSongs);
	
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE
	quickSort(mySongArray, 0, numSongs-1);
	
	
	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outFile.open("sortFileQuick.txt");
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	delete [] mySongArray;
	return 0;
}

//LOOK!  WRITE YOUR INSERTION SORT FUNCTION HERE
void insertionSort(Song* arr, int numSongs)
{
	Song key;
	int j;
	
	for (int i = 1; i < numSongs; i++)
	{
		key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j].getTitle() >= key.getTitle()) 
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
	arr[j+1] = key;
	}
}


//LOOK!  WRITE YOUR REVERSE BUBBLE SORT FUNCTION HERE
void bubbleSort(Song *arr, int size)
{
	Song tempForSwap;

	for(int maxElement=(size-1); maxElement > 0; maxElement--)
	{
		for(int i=0; i < maxElement; i++)
		{
			if(arr[i].getTitle() < arr[i+1].getTitle()) 
			{
				tempForSwap = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tempForSwap;
			}
		}
	}
}


//LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE
void quickSort(Song *arr, int low, int high) 
{
	int pivot_location = 0;

	/* Base case: If there are 1 or zero elements to sort,
	partition is already sorted */
	if (low >= high) {
		return;
	}

	/* Partition the data within the array. */
	pivot_location = partition(arr, low, high); //returns location of last element in low partition
	quickSort(arr, low, pivot_location); //recursively sort low partition
	quickSort(arr, pivot_location + 1, high); //recursively sort high partition
}


//LOOK!  WRITE YOUR PARTITION FUNCTION HERE
int partition(Song *arr, int left, int right) 
{

   Song pivot, temp;
   int middle;
   bool done = false;
   
   //pivot starts at middle
   middle = left + (right-left) / 2;
   pivot = arr[middle];
   int l = left;
   int r = right;
   while(!done)
   {
		while(arr[l].getTitle() < pivot.getTitle()) //increment l while arr[l] < pivot
		   ++l;
		while(pivot.getTitle() < arr[r].getTitle())//decrement r while pivot < arr[r]
		   --r;
		
		//if there are 0 or 1 elements remaining, all numbers are partiioned.  return r
		if(l >= r)
			done = true;
		else
		{
			//swap & update l and r
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			++l;
			--r;
		}
   }
   return r;   
}
