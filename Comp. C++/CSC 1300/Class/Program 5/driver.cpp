#include "items.h"

int main()
{
	
	int facNum;
	Items* facArray;
	int choiceNum;
	int currNum = 0;
	int whileCheck = 0;
	
	cout << "What is the maximum number of items your factory can hold?" << endl;
	cin >> facNum;
	
	while (facNum < 0)
	{
		cout << "\nYou have entered an invalid number. Please try again: ";
		cin >> facNum;
	}
	
	facArray = new Items [facNum];
	
	do
	{
		
	choiceNum = menuFunc();
	
	switch (choiceNum)
	{
		case 1: itemAdd(facArray, facNum, currNum);
				break;
		case 2: printItems(facArray, currNum);
				break;
		case 3: saveInventory(facArray, currNum);
				cout << "\n\nGoodbye!";
				return 0;
	}
	
	}while(whileCheck == 0);
	
	delete [] facArray;
	
return 0;
}