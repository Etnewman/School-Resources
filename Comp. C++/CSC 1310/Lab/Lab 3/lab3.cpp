/*
	Title:  Lab3.cpp
	Author: YOUR NAME HERE!!!
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	bool  boolVar;
	srand(time(NULL));
	string userString, userStrWithoutSpaces, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << sumOfNumbers(num);
				
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				boolVar = isMember(myArray, num, ARRAY_SIZE);
					if (boolVar == true)
					{
						cout << "\nYes " << num << " was in the array\n";
					}
					if (boolVar == false)
					{
						cout << "\nNo " << num << " was NOT in the array\n";
					}
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				stringReverser(userString);
				
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				
				boolVar = isPalindrome(userStrModified);
				
				if (boolVar == true)
				{
					cout << "\nYES! This is a Palindrome!\n";
				}
				if (boolVar == false)
				{
					cout << "\nNO! This is not a Palindrome!\n";
				}
				
				
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				cout << multiply(num1,num2);
				
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}

int sumOfNumbers(int num)
{
	if(num != 0)	
	{
		return num + sumOfNumbers(num-1);
	}
	else		
	{
		cout << "\n\nThe Result is: " << num;
		return num;
		
	}
}

bool isMember(int* myArray, int key, int size)
{
	size = size - 1;
	
	if (size < 0)
	{
		return false;
	}
	else if(myArray[size]==key)
	{
		return true;
	}
	else{
	return isMember(myArray, key, size);
	}
}

void stringReverser(string userString)
{
	int numChar = userString.size();
	
		if (numChar == 0)
		{
			return;	
		}
		else
		{
			stringReverser(userString.substr(1));
			cout << userString[0];
		}
}
	
bool isPalindrome(string userString)
{
	if(userString.length() < 2)
	{
		return true;
	}
	
	if (userString[0] != userString[userString.length() - 1])
	{
		return false;
	}
	
	string temp = userString.substr(1, userString.length() - 2);
	if (!isPalindrome(temp))
	{
		return false;
	}
	return true;
}

int multiply(int x, int y)
{
	if (y==0)
	{
		return 0;
	}
	
	else
	{
		return x+multiply(x,y-1);
	}

}


//implement the five recursive functions below!!!!
