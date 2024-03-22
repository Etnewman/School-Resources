/*
	Title: strlenPrac.cpp
	Author:  April Crockett
	Date:  8/2/2017
	Purpose:  demonstrate the c-string function strlen
*/
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char name[50] = "Bram Crockett";
	int length;
	
	length = strlen(name);
	cout << "The length of " << name << " is: " << length << endl;
	
	length = strlen("Cletus Yella Cat Crockett");
	cout << "The length of Cletus Yella Cat Crockett is: " << length << endl;
	
	return 0;
}