/*
	Title: Lab3a.cpp
	Author: Ethan Newman
	Date: 1/31/2019
	Purpose: Debugging and troubleshooting
*/

#include<iostream>
#include<string>
using namespace std;

int main ()
{
	const double PI = 3.14159;
	double circumference, diameter;
	string fullName;
	
	cout << "\n\nWhat is the diameter of the circle?\n";
	cin >> diameter;
	cin.ignore();
	
	cout << "\n\nWhat is your first & last name?\n";
	getline(cin, fullName);

	 circumference = PI * diameter;

	
	cout << "\n\nHello, " << fullName;
	cout << "! The circumference of your circle is: " << circumference;
	cout << endl << endl;
	
	return 0;
}