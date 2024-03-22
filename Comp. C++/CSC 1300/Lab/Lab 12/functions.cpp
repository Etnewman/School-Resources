#include "jellybelly.h"
//FIXME - add all other programmer-defined function definitions in this file!!!



/*
	Function: 	convertToFloat
	Purpose:  	This funciton accepts a string, converts the string to
				a c-string, and then converts the c-string to a float.
				Then, returns this float from the function.
*/

float convertToFloat(string str)
{
	float number;
	char convertStr[1000];
	strcpy(convertStr, str.c_str()); //convert the string to c-string
	
	number = atof(convertStr);
	
	return number;
}

/*
	Function:  	deleteBeans
	Purpose:  	This funciton will allow the user to delete or remove a kind
				of jellybean from inventory.  If kind was successfully removed
				then this function subtracts one from the current number of 
				kinds in inventory and returns this integer from the function.
*/

int deleteBeans(Jellybean jellybeanArray[], int num)
{
	string flavorChoice;
	bool removed = false;
	
	cout << "\n\nChoose a jellybelly kind to remove from inventory!\n\n";
	for(int x=0; x<num; x++)
	{
		cout << jellybeanArray[x].flavor << "\n";
	}
	cout << "\nFLAVOR TO DELETE:  ";
	cin.ignore();
	getline(cin, flavorChoice);
	for(int x=0; x<num; x++)
	{
		if(flavorChoice == jellybeanArray[x].flavor)
		{
			removed = true;
			for(int y=x; y<(num-1); y++)
			{
				jellybeanArray[y] = jellybeanArray[y+1];
			}
		}
	}
	if(removed == true)
	{
		num--;
		cout << flavorChoice << " was removed from the inventory.\n\n";
	}
	else
		cout << flavorChoice << " does not exist in the inventory.\n\n";
	
	return num;
	
}

/*
	Function:	displayMenuGetChoice
	Purpose:	This function will call a menu for the user and get an integer returned 
				that corresponds to the users choice.
*/

int displayMenuGetChoice()
{
	int menuChoice = 0;
	
	cout << "\nPlease pick from the following:" << endl;
	cout << "	1.	Print jellybean inventory" << endl;
	cout << "	2.	Print how many jellybeans in a particular color" << endl;
	cout << "	3.	Add to inventory" << endl;
	cout << "	4.	Delete from inventory" << endl;
	cout << "	5.	Save inventory & end the program" << endl;
	cout << "Please enter a number 1 - 5: ";
	
	cin >> menuChoice;

	while (menuChoice > 5 || menuChoice < 1) 
	{
		cout << "\nYou have entered an invalid number. Please try again: ";
		cin >> menuChoice;
	}
	
	return menuChoice;
}

/*
	Function: printAllInventory
	Purpose: To print all data currently stored in the Jellybean Structure
*/

void printAllInventory(Jellybean jellybeanArray[], int currentNum)
{
	for ( int i = 0; i < currentNum; i++)
	{
		cout << "\n\n-----------------------------------------------";
		cout << "\nFLAVOR: " << jellybeanArray[i].flavor;
		cout << "\nCOLOR: " << jellybeanArray[i].color;
		cout << "\nRATING: " << jellybeanArray[i].starRating;
		cout << "\nPRICE: " << jellybeanArray[i].pricePerLb;
		cout << "\nSTOCK: " << jellybeanArray[i].quantityLbs << endl;
	}
}

/*
	Function:	printColor
	Purpose:	This function asks the user what color jelly bean they want to print from
				the inventory, then it will print out how man jelly beans share that color.
*/

void printColor(Jellybean jellybeanArray[], int currentNum)
{
	string jellyChecky;
	int num = 0;
	
	cout << "\nChoose from:" << endl;
	cout << "\n		beige	black	brown	blue	green" << endl;
	cout << " 		multi-colored	orange	pink	purple	red" << endl;
	cout << "		white	yellow" << endl;
	
	
	cout << "\nWhat color Jelly bean do you want to print out?" << endl;
	cin.ignore();
	getline(cin, jellyChecky);
	
	for ( int i = 0; i < currentNum; i++)
	{
		if (jellyChecky == jellybeanArray[i].color)
		{
			cout << "\n\n-----------------------------------------------";
			cout << "\nFLAVOR: " << jellybeanArray[i].flavor;
			cout << "\nCOLOR: " << jellybeanArray[i].color;
			cout << "\nRATING: " << jellybeanArray[i].starRating;
			cout << "\nPRICE: " << jellybeanArray[i].pricePerLb;
			cout << "\nSTOCK: " << jellybeanArray[i].quantityLbs << endl;
		
			num++;
		}
	}
	
	if (num == 0)
	{
		cout << "\nSorry, there were no jellybean types in inventory with that color." << endl;
	}
	else if (num == 1)
	{
		cout << "\nThere was one jellybean type with that color" << endl;
	}
	else
	{
		cout << "\nThere are " << num << " jellybean types with that color." << endl;
	}
}

int addBeans(Jellybean jellybeanArray[], int num) 
{
	cout << "\nAdd a jellybelly kind to inventory!" << endl;
	cout << "\nFLAVOR: ";
	
	cin >> jellybeanArray[num+1].flavor;
	
	cout << "\n\n	beige	black	brown	blue	green" << endl;
	cout << "	multi-colored   orange	pink	purple" << endl;
	cout << "	red		white	yellow" << endl;
	cout << "\nCOLOR: ";
	
	cin >> jellybeanArray[num].color;

	cout << "\nRATING (NUMBER STARS): ";
	
	cin >> jellybeanArray[num].starRating;
	
	cout << "\nPRICE PER POUND: ";
	
	cin >> jellybeanArray[num].pricePerLb;
	
	cout << "\nQUANTITY IN POUNDS: ";
	
	cin >> jellybeanArray[num].quantityLbs;
	
	return num;
}
	

	


















