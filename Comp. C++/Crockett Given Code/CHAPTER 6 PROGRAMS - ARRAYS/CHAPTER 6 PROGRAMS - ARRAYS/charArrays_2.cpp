/*
	Title:  charArrays_2.cpp
	Author:  Gaddis, modified by Crockett
	Date:  8/2/2017
	Purpose:  This program has a partially initialized array.
*/
#include <iostream>
using namespace std;

int main()
{
	int arrayName[] = {10, 20, 30, 40, 50};  //implicit array sizing
	char name[] = "Ruth";

	//demonstrate that the array elements are not printed out with single cout statement
	//unless it is a c-string
	cout << arrayName << endl;
	cout << name << endl;

	for(int x=0; x<5; x++)
		cout << arrayName[x] << endl;

	//this will work for c-strings too
	for(int x=0; x<5; x++)
		cout << name[x] << endl;
	
	return 0;
}