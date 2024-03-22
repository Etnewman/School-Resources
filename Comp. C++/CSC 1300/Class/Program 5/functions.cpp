#include "items.h"

/*
	Name: Menu Function
	Purpose: To print out a menu for the user and recieve an input that correlates to the menu printed.
*/

int menuFunc()
{
	
	int num;

	cout << "\n\nPlease choose from the following options:" << endl;
	cout << "1.	Add awesome item(s)." << endl;
	cout << "2.	Print all Items." << endl;
	cout << "3.	End the Program." << endl;
	cout << "\nCHOOSE 1 - 3: " ;
	
	cin >> num;
	
	while (num > 3 || num < 0)
	{
		cout << "\nYou have entered an invalid number. Please try again: ";
		cin >> num;
	}

return num;
}



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
	strcpy(convertStr, str.c_str()); 
	
	number = atof(convertStr);
	
	return number;
}



/*
	Name: Item Add Function
	Purpose: To get user input in adding items from either the inventory or 
	manually add items from the user.
*/

void itemAdd(Items facArray[], int facNum, int& currNum)
{
	int userNum;
	string userFile;
	string temp;
	string data;
	int whileCheck = 0;
	
	do 
	{
	
	if (currNum >= facNum)
	{
		cout << "\n\nOOPS! Your factory is full." << endl;
		break;
	}
	else
	{
	
	
	cout << "\n\nPlease chhose from the following options:" << endl;
	cout << "1.	Add items from a file." << endl;
	cout << "2.	Add one item manually." << endl;
	cout << "3.	Return to main menu." << endl;
	cout << "CHOOSE 1 - 3: ";
	
	cin >> userNum;
	cin.ignore();
	
	while (userNum > 3 || userNum < 0)
	{
		cout << "\nYou have entered an invalid number. Please try again: ";
		cin >> userNum;
	}
	
	if (userNum == 1)
	{
		cout << "\n\nWhat is the name of the file that contains the inventory items?" << endl;
		getline(cin, userFile);
		
		ifstream inFile;
		inFile.open(userFile.c_str());
		
		if(inFile.good())
		{
			getline(inFile, data, '#');
			while (!inFile.eof() && currNum != facNum)
			{
				facArray[currNum].name = data;
				
				getline(inFile, facArray[currNum].descrp, '#');
				getline(inFile, data, '#');
				
				facArray[currNum].Cost.matCost = convertToFloat(data);
				getline(inFile, data, '#');
				
				facArray[currNum].Cost.saleCost = convertToFloat(data);
				getline(inFile, data, '#');
				
				facArray[currNum].Cost.profit = convertToFloat(data);
				getline(inFile, data, '#');
	
				facArray[currNum].numStores = convertToFloat(data);
				
				facArray[currNum].nameStores = new string[facArray[currNum].numStores];
				
				for (int i = 0; i < facArray[currNum].numStores; i++)
				{
					getline(inFile, facArray[currNum].nameStores[i], '#');
				}
				
				getline(inFile, facArray[currNum].creationDate, '#');
				getline(inFile, data, '#');
				
				
				currNum++;
			}			
		inFile.close();
		}
		
		cout << "\n\nThe file read in "<< currNum << " item(s) into the inventory." << endl;
		
	}
	
	if (userNum == 2)
	{
		cin.ignore();
		cout << "\nWhat is the name of your item?" << endl;
		getline(cin, facArray[currNum].name);
		
		cout << "\n\nDescribe the item in detail." << endl;
		getline(cin, facArray[currNum].descrp);
		
		cout << "\n\nWhat is the cost to create this item?" << endl;
		cin >> facArray[currNum].Cost.matCost;
		
		cout << "\n\nWhat is the price you are going to sell this item?" << endl;
		cin >> facArray[currNum].Cost.saleCost;
		
		facArray[currNum].Cost.profit = facArray[currNum].Cost.matCost - facArray[currNum].Cost.saleCost;
		
		cout << "\n\nHow many stores are going to sell this item?" << endl;
		cin >> facArray[currNum].numStores;
		cin.ignore();
	
		facArray[currNum].nameStores = new string[facArray[currNum].numStores]; 
		
		cout << "\n\nWhat are the name(s) of these stores?" << endl;
		
		for (int j = 0; j < facArray[currNum].numStores; j++)
		{
			cout << "\nSTORE " << j+1 << " : ";
			getline(cin, facArray[currNum].nameStores[j]);
		}
		
		cout << "\n\nWhen was this item created? (MM DD YY)" << endl;
		getline(cin, facArray[currNum].creationDate);
		
		currNum++;
		
		cout << "\n\nYou currently have " << currNum << " item(s) in your inventory." << endl;
	}
	
	else
	{
		whileCheck = 1;
	}
	}
	}while (whileCheck == 0);
}


/*
	Title: Print Item(s) Function
	Purpose: To print all stored items in the facArray out into the cmd prompt to the user.
*/
	
void printItems(Items facArray[], int& currNum)
{
	if (currNum == 0)
	{
		cout << "\n\nThere are no items to print." << endl;
	}
	
	else
	{
		for (int i = 0; i < currNum; i++)
		{
			
				cout << "\n\n-----------------------------------------------------------------" << endl;
				cout << "										Item " << i+1 << endl;
				cout << "NAME: " << facArray[i].name << endl;
				cout << "\nDESCRIPTION: " << facArray[i].descrp << endl;
				cout << "\nGOODS PRICE: " << facArray[i].Cost.matCost << endl;
				cout << "\nSALE PRICE: " << facArray[i].Cost.saleCost << endl;
				cout << "\nPROFIT: " << facArray[i].Cost.profit << endl;
				cout << "\nSTORES WHO SALE THIS ITEM: " << endl;
				
				for (int x = 0; x < facArray[i].numStores; x++)
				{
					cout << "		STORE " << x+1 << " NAME: " << facArray[i].nameStores[x] << endl;
				}
				cout << "\nAQUIRE DATE: " << facArray[i].creationDate << endl;
			}
		}
	}

/*
	Name:
	Purpose:
*/
	
void saveInventory(Items facArray[], int& currNum)
{
	string fileName;
	
	if (currNum == 0)
	{
		cout << "\n\nThere are no items to save to a file." << endl;
	}
	
	else
	{
		cout << "\n\nWhat would you like to name the file this information will be saved to?" << endl;
		cin.ignore();
		getline(cin, fileName);
		
		ofstream outfile;
	
		outfile.open(fileName.c_str());
		
		if(outfile.good())
		{
			for (int i = 0; i < currNum; i++)
			{
				outfile << facArray[i].name << '#';
				outfile << facArray[i].descrp << '#';
				outfile << facArray[i].Cost.matCost << '#';
				outfile << facArray[i].Cost.saleCost << '#';
				outfile << facArray[i].Cost.profit << '#';
				outfile << facArray[i].numStores << '#';
				
				for (int x = 0; x < facArray[i].numStores; x++)
				{
					outfile << facArray[i].nameStores[x] << '#';
				}
				
				outfile << facArray[i].creationDate << '#';
			}
		}
	
	cout << "\n\nAll your items have been saved to "<< fileName << endl;
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	