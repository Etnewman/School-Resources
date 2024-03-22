/*
	Program 1
	Ethan Newman
	2400-002
*/

#include "Lexo.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	bool whileCheck = true;
	bool quitCheck = false;
	
	int count = 0;
	string strArray[100];
	
	cout << "Enter in strings until either you type quit or you enter in 100 strings.\n";
	
	while(whileCheck)
	{
		if(count == 100)
			whileCheck = false;
		
		cout << "\nPlease enter in a string:";
		getline(cin, strArray[count]);
		
		if (strArray[count] == "Quit" || strArray[count] == "quit")
		{
			whileCheck = false;
			quitCheck = true;
		}
		
		count++;
	}
	
	if (quitCheck == true)
	{
		strArray[count-1].clear();
		count--;
	}
	
	cout << "\nNow sorting by length...\n";
	sortLength(strArray, count);

	cout << "\nNow sorting alphabetically...\n";
	
	//Using vector to use sort()
	vector<string> strVector (strArray, strArray + count);
	
	sort(strVector.begin(), strVector.end(), compare);
	
	for (int i = 0; i < count; i++)
	{
		strArray[i] = strVector[i];
	}
	
	cout << "\n\nLexocographic Alogrithm...\n\n";
	
	do{
		display(strArray, count);
	}while(next_permutation(strArray, strArray + count));
		
	
	return 0;
}


//-------------------------------------------------------------------------------



//Sorts the String array by length
void sortLength(string arr[], int count)
{
	for (int i = 1; i < count; i++)
	{
		string temp = arr[i];
		
		int j = i - 1;
		while (j >= 0 && temp.length() < arr[j].length())
		{
			arr[j+1] = arr[j];
			j--;
		}
		
		arr[j+1] = temp;
	}
}

//helps vector use sort()
bool compare(string a, string b)
{
	return (a.compare(b) < 0);
}	

void display(string arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}






