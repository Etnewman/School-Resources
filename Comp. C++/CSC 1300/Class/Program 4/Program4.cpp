/*
	Title: MADLIBS!!! (Program 4)
	Author: Ethan Newman
	Date: 4/4/2019
	Purpose: TO PLAY MADLIBS!!!
*/

#include<iostream>
#include<fstream>

using namespace std;

int showMenuGetChoice(); //Shows Menu, gets input from user, returns integer.
string* createStringArray(int arraySize); //Creates Dynamicly Allocated  Arrays
void getInfoFromUser(int arraySize, string* dynArrayQs, string* dynArrayAns); //Gets user's input into Dynamic Array
void printStory(string* dynArrayAns, string* dynArrayStory, int arraySize); //Prints User's answers and story created from Arrays





int main()
{
	int whileCheck = 0;
	
	do {
		
	char charCheck;
	int numChoice = 0;
	int arraySize = 0;
	string* dynArrayQs = NULL;
	string* dynArrayAns = NULL;
	string* dynArrayStory = NULL;
	
	
	cout << "Let's Play some MADLIBS!!" << endl;

	numChoice = showMenuGetChoice();
	
		if (numChoice == 1)
		{
			ifstream myfile ("starWars.txt");
			
			if (myfile.is_open())
			{
			
				myfile >> arraySize;
				
				dynArrayQs = createStringArray(arraySize);
				dynArrayAns = createStringArray(arraySize);
				dynArrayStory = createStringArray(arraySize);
				
				myfile.ignore();
				
					for (int i = 0; i < arraySize; i++)
					{
						getline(myfile, dynArrayQs[i]);
					}
					
			getInfoFromUser(arraySize, dynArrayQs, dynArrayAns);
			
			myfile.close();
			
			ifstream storyfile ("starWarsText.txt");
			
				if (storyfile.is_open()) 
				{
					for (int j = 0; j < arraySize; j++) 
					{
						getline(storyfile, dynArrayStory[j]);
					}
				}
				
				storyfile.close();
			
			printStory(dynArrayAns, dynArrayStory, arraySize);
			
			}
		}
		
		if (numChoice == 2)
		{
			ifstream myfile ("dog.txt");
		
			if (myfile.is_open())
			{
			
				myfile >> arraySize;
				
				
				dynArrayQs = createStringArray(arraySize);
				dynArrayAns = createStringArray(arraySize);
				dynArrayStory = createStringArray(arraySize);
				
				myfile.ignore();
				
					for (int i = 0; i < arraySize; i++)
					{
						getline(myfile, dynArrayQs[i]);
					}
					
			getInfoFromUser(arraySize, dynArrayQs, dynArrayAns);
			
			myfile.close();
			
			ifstream storyfile ("dogText.txt");
			
				if (storyfile.is_open()) 
				{
					for (int j = 0; j < arraySize; j++) 
					{
						getline(storyfile, dynArrayStory[j]);
					}
				}
				
				storyfile.close();
				
				printStory(dynArrayAns, dynArrayStory, arraySize);
			
			}
		}
		
		if (numChoice == 3)
		{
			ifstream myfile ("pirate.txt");
			
			if (myfile.is_open())
			{
			
				myfile >> arraySize;
				
				dynArrayQs = createStringArray(arraySize);
				dynArrayAns = createStringArray(arraySize);
				dynArrayStory = createStringArray(arraySize);
				
				myfile.ignore();
				
					for (int i = 0; i < arraySize; i++)
					{
						getline(myfile, dynArrayQs[i]);
					}
					
			getInfoFromUser(arraySize, dynArrayQs, dynArrayAns);
			
			myfile.close();
			
			ifstream storyfile ("pirateText.txt");
			
				if (storyfile.is_open()) 
				{
					for (int j = 0; j < arraySize; j++) 
					{
						getline(storyfile, dynArrayStory[j]);
					}
				}
				
				storyfile.close();
				
				printStory(dynArrayAns, dynArrayStory, arraySize);
			
			}
		}
		
		if (numChoice == 4)
		{
			cout << "\nYou have decided to end the program.";
			return 0;
		}
		

	delete [] dynArrayQs;
	delete [] dynArrayAns;
	delete [] dynArrayStory;
	
	cout << "\n\nWould you like to play again? (Y/N) : ";
	cin >> charCheck;
	
		while (charCheck != 'y' || charCheck != 'Y' || charCheck != 'n' || charCheck != 'N')
		{
			cout << "\nYou have entered an invalid character. Please try again: ";
			cin >> charCheck;
		}
		
		if (charCheck == 'y' || charCheck == 'Y')
		{
		}
		else
		{ 
		return 0;
		}
		
	} while (whileCheck == 0);

	return 0;
}

int showMenuGetChoice()
{
	int numChoice = 0;
	
	cout << "\nChoose a MAD LIBS Game:" << endl;
	cout << "1. The Power of the Force (Star Wars Mad Libs)" << endl;
	cout << "2. Dog Days (Dog Ate My Mad Libs)" << endl;
	cout << "3. Talking Like a Pirate (Pirates Mad Libs)" << endl;
	cout << "4. END GAME" << endl;
	cout << "\n CHOOSE 1-4:  ";
	
	cin >> numChoice;
	
	while (numChoice < 0 || numChoice > 4)
	{
		cout << "\nYou have entered an invalid choice. Please try again: ";
		cin >> numChoice;
	}
	
	return numChoice;
	
}

string* createStringArray(int arraySize)
{
	string* tempArr = NULL;
	
	tempArr = new string [arraySize];
		
	return tempArr;
}

void getInfoFromUser(int arraySize, string* dynArrayQs, string* dynArrayAns)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << dynArrayQs[i] << " : ";
		cin >> dynArrayAns[i];
		cout << endl;
	}
}
		
void printStory(string* dynArrayAns, string* dynArrayStory, int arraySize)
{
	
	for (int i = 0; i < arraySize; i++) 
	{ 
		cout << dynArrayStory[i] << dynArrayAns[i];
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

