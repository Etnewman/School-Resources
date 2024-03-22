/*
	Title: Lab 12
	Name: Ethan Newman && Lindasy Easterwood
	Purpose: To accurately inventory Jelly Belies
	Date: 4/11/19

*/

#include "jellybelly.h"

int main()
{
	Jellybean jellybeanArray[NUM_FLAVORS];
	int menuChoice = 0;
	
	ifstream inFile;
	string data;
	int currentNum = 0;  //keeps track of how many kinds of jellybeans are in inventory right now
	
	cout << "\n\nWelcome to JellyBelly Factory!\n\n";
	
	
	//Load the inventory
	inFile.open("jellybellyInventory.txt");
	if(inFile.good())
	{
		getline(inFile, data, '*');
		while(!inFile.eof() && currentNum != NUM_FLAVORS)
		{
			jellybeanArray[currentNum].flavor = data;
			getline(inFile, jellybeanArray[currentNum].color, '*');
			getline(inFile, data, '*');
			jellybeanArray[currentNum].starRating = stringToFloat(data);
			getline(inFile, data, '*');
			jellybeanArray[currentNum].pricePerLb = stringToFloat(data);
			getline(inFile, data, '*');
			jellybeanArray[currentNum].quantityLbs = stringToFloat(data);
			
			
			currentNum++;
			getline(inFile, data, '*');
		}
		cout << "\n\nThere are currently " << currentNum << " items in inventory.\n\n";
		inFile.close();
	}
	else{
		cout << "\n\nThere are currently no items in inventory.\n\n";
	}
	
	do
	{
		menuChoice = displayMenuGetChoice();
		
		switch (menuChoice)
		{
			case 1: printAllInventory(jellybeanArray, currentNum);
					break;
			case 2: printColor(jellybeanArray, currentNum);
					break;
			case 3: currentNum = addBeans(jellybeanArray, currentNum);
					break;
			case 4: currentNum = deleteBeans(jellybeanArray, currentNum);
					break;
		}
		
	} while(menuChoice != 5);
	
	cout << "\n\nSaving inventory....\n\n";
	
	ofstream outfile;
	
	outfile.open("jellybellyInventory.txt");
	if(outfile.good())
	{
		for (int j = 0; j < NUM_FLAVORS; j++)
		{
			outfile << jellybeanArray[j].flavor << '*';
			outfile <<jellybeanArray[j].color << '*';
			outfile <<jellybeanArray[j].starRating << '*';
			outfile <<jellybeanArray[j].pricePerLb << '*';
			outfile <<jellybeanArray[j].quantityLbs << '*';
		}
		outfile.close();
	}
	
	
	cout << "Goodbye!\n\n";	
	
	return 0;
}