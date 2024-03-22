/*
	Title: Lab3a.cpp
	Author: Ethan Newman
	Date: 1/31/2019
	Purpose: Variable, simple input, simple output and casting
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{

	int int1;
	double dbl1;
	char char1;
	string str;
	
	cout << "Enter Integer:" << endl;
	cin >> int1;
	
	cout << "\nEnter Double:" << endl;
	cin >> dbl1;
	
	cout << "\nEnter Character:" << endl;
	cin >> char1;
	cin.ignore();
	
	cout << "\nEnter String:" << endl;
	getline (cin,str);
	
	cout << "\n " << int1 << "\n " << dbl1 << "\n " << char1 << "\n " << str << "\n ";
	
	cout << dbl1 << " cast to an integer is " << static_cast<int>(dbl1);
	
	return 0;
}