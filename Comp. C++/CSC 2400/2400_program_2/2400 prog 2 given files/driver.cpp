/*
     Title:     
     Author:    
     Date:      
     Purpose:   Traveling Salesman - find the lowest cost
                tour when traveling from US to 8 other countries
                and then back to US.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include "GraphMatrix.h"
using namespace std;

const int SIZE = 10;
const string COUNTRY_CODES[SIZE]={"AU", "BR", "CA", "CN", "GL", "IT", "NA", "RU", "US", "US"};

/*
	Use the following structure to store each tour & its cost
	You will create an array of Tour variables in your program
*/
struct Tour
{
	string tour[SIZE];
	int cost;
};

//Function Prototypes
int searchCountryCode(string);
GraphMatrix* readFileMakeMatrix();
void printStringArray(string* arr, int size);
void lexico(string *arr, Tour *tour, GraphMatrix *matrix);
void swap(string *arr, int x, int n);
void reverse(string *arr, int x, int n);
void saveTour(Tour *tourOptions, int index);
int findLowest(Tour *tourOptions);

int main()
{	
	Tour *tourOptions = new Tour[40320];
	//read in the flight information from the file and then create the weight matrix
	GraphMatrix * matrix = readFileMakeMatrix();
	string * countries = new string[SIZE-2];
	
	cout << "\n\n*************************COUNTRIES*******************\n";
	for(int x=0; x < SIZE-2; x++)
	{
		countries[x] = COUNTRY_CODES[x];
		cout << countries[x] << endl;
	}
	
	cout << "\n\n\n";
	
	//generate all possible tours (starting & ending with "US") using lexicographic permute algorithm
	//you will need to call your lexicographic function, sending the modified countries array with the 8 country codes
	lexico(countries, tourOptions, matrix);
	cout << "\n\n*************************SOLUTION*******************\n";
	//find the lowest cost tour and print it out (including the cost)
	
	int index = findLowest(tourOptions);
	
	cout << "\n\n****************************************************\n";
	
	saveTour(tourOptions, index);
	
	cout << "\nHappy Traveling!\n";
	
	//don't forget to release anything that was dynamically allocated!
	return 0;
}
/*
	Function: searchCountryCode
	Parameters: a string with the country code like "US"
	Returns: an integer representing this country's index in the GraphMatrix
	
	Implement this search function with the binary search algorithm!
*/
int searchCountryCode(string code)
{
	int l = 0;
	int r = SIZE-1;
	
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		
		if(COUNTRY_CODES[m] == code)
			return m;
		
		if(COUNTRY_CODES[m] < code)
			l = m + 1;
		else
			r = m - 1;
	}
	
	return -1;
}

/*
	Title: readFileMakeMatrix
	Purpose:  this function will read the data in flights.txt and create an
	adjacency matrix with the couuntry codes.  The matrix values will be the
	cost of the flights.
*/
GraphMatrix* readFileMakeMatrix()
{
	ifstream inFile;
	GraphMatrix * matrix = new GraphMatrix(SIZE-1);
	cout << "\nCreated the matrix.";
	string country1, country2;
	int price;
	inFile.open("flights.txt");
	cout << "\nReading from flights.txt\n";
	if(inFile)
	{
		while(inFile >> country1)
		{
			inFile >> country2;
			inFile >> price;
			//add price to graph matrix
			matrix->addEdge(searchCountryCode(country1), searchCountryCode(country2), price);
			cout << "\nAdded edge from " << country1 << " to " << country2 << " with cost of $" << price;
		}
	}
	else
		cout << "\nSorry, I am unable to open the file.\n";
	inFile.close();
	cout << "\n\nFLIGHT PRICE GRAPH MATRIX\n";
	matrix->printGraph();
	cout << endl;
	return matrix;
}

/*
	Title: printStringArray
	Purpose:  this function will print the array of strings with a space
		between each string
*/
void printStringArray(string* arr, int size)
{
	for(int x=0; x<size; x++)
	{
		cout << arr[x] << " ";
	}
	cout << endl;
}


/*
	Title: reverse
	Purpose: To reverse the index of i and j from the Lexico Alg. This will 
			 allow me to get all possible permutations in my Array.
*/
void reverse(string *arr, int x, int n){
  int j = n-1;

  while (x < j)
  {
		swap(arr, x, j);
		x++;
		j--;
  }
}

/*
	Title: swap
	Purpose: To swap two indcies 
*/
void swap(string *arr, int x , int n)
{
	string temp;
	temp = arr[x];
	arr[x] = arr[n];
	arr[n] = temp;
}

/*
	Title: Lexico
	Purpose: Lexicographic Permutation, used to complete the traveling
			 salesman challenge.
*/
void lexico(string *arr, Tour *tourOptions, GraphMatrix *matrix)
{
	int trueI = -10;
	int trueJ = -10;
	int permutations = 1;
	int check = 0;
	
	cout << permutations << ".\t" << arr[0] << " ";
	
		for (int x = 0; x < SIZE-3; x++)
		{
			cout << arr[x+1] << " ";
			tourOptions[check].tour[x] = arr[x];
			tourOptions[check].cost += matrix->getWeight(searchCountryCode(arr[x]), searchCountryCode(arr[x+1]));
		}
		
		tourOptions[check].tour[7] = arr[7];
		tourOptions[check].cost += matrix->getWeight(searchCountryCode("US"), searchCountryCode(arr[SIZE-3]));
		tourOptions[check].cost += matrix->getWeight(searchCountryCode(arr[0]), searchCountryCode("US"));

	cout << "\t TOUR PRICE: " << tourOptions[check].cost << endl;
	
	check++;
	
	do
	{
		
		trueI = -10;
		trueJ = -10;
		tourOptions[check].cost = 0;
		
		for (int i = 0; i < SIZE - 3; i++)
		{
			if(arr[i] < arr[i+1])
				trueI = i;
		}
			
		for (int j = trueI+1; j < SIZE - 2; j++)
		{
			if(arr[trueI] < arr[j])
				trueJ = j;
		}
		
		swap(arr, trueI, trueJ);
		reverse(arr, trueI+1, SIZE - 2);
		
		if (trueI > -1 && trueJ > -1)
		{
			permutations++;
			cout << permutations << ".\t" << arr[0] << " ";
			for (int k = 0; k < SIZE-3; k++)
			{
				cout << arr[k+1] << " ";
				tourOptions[check].tour[k] = arr[k];
				tourOptions[check].cost += matrix->getWeight(searchCountryCode(arr[k]), searchCountryCode(arr[k+1]));				
			}
			
			tourOptions[check].tour[7] = arr[7];
			tourOptions[check].cost += matrix->getWeight(searchCountryCode("US"), searchCountryCode(arr[SIZE-3]));
			tourOptions[check].cost += matrix->getWeight(searchCountryCode(arr[0]), searchCountryCode("US"));
			cout << "\t TOUR PRICE: " << tourOptions[check].cost << endl;
			
		}
		
		if (trueI == -10)
		{
			check = 40320;
			break;
		}
		else if (trueJ == -10)
		{
			check = 40320;
			break;
		}
		
		check++;
		
	}while (check < 40320);
	
	//int index = findLowest(tourOptions);
	//saveTour(tourOptions, index);
	
}

void saveTour(Tour *tourOptions, int index)
{
	cout << "\n\nThe lowest cost tour is: US " << tourOptions[index].tour[0] << " ";		
	for (int j = 0; j < SIZE-3; j++)
	{
		cout << tourOptions[index].tour[j+1] << " ";
	}	
	cout << "US\t TOUR PRICE: " << tourOptions[index].cost << endl;
	
	
}

int findLowest(Tour *tourOptions)
{
	int lowest = tourOptions[0].cost;
	int index = 0;
	
	for (int i = 0; i < 40319; i++)
	{
		if (tourOptions[i].cost < tourOptions[i+1].cost && lowest > tourOptions[i].cost)
		{
			lowest = tourOptions[i].cost;
			cout << "\nNEW LOWEST FOUND! " << tourOptions[i].tour[0] << " ";
			
			for (int j = 1; j < SIZE-2; j++)
			{
				cout << tourOptions[i].tour[j] << " ";
			}
			
			cout << "\tWITH PRICE OF: " << tourOptions[i].cost;
			index = i;
			//cout << "\n\n" << index;
		}
	}
	
	return index;
}
	


