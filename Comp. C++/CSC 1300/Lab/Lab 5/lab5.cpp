/*
	Title: Lab5.cpp
	Author: Ethan Newman
	Date: 2/14/2019
	Purpose: Text Message Expander
*/

#include<iostream>
#include<string>
using namespace std;

int main ()
{
	string textMsg;
	string textAbbr[10] = {"BFF",
	"IDK",
	"JK",
	"TMI",
	"TTYL",
	"YMMD",
	"W8",
	"QT",
	"AYTMTB",
	"DAB"	};
	string textExp [10] = {"best friend forever",
	"I don't know",
	"just kidding",
	"too much information",
	"talk to you later",
	"you made my day",
	"wait",
	"cutie",
	"and you're telling me this because",
	"drink a beer" };
	
	int stringNum, i;
	i=0;
	
	cout << "Enter Text: ";
	getline(cin, textMsg);
	cout << "\nYou entered: " << textMsg << endl;
	do
	{	
		if (textMsg.find(textAbbr[i]) != string::npos)
		{
		stringNum = textMsg.find(textAbbr[i]);
		textMsg = textMsg.replace(stringNum, textAbbr[i].length(), textExp[i]);
		}
	i++;
	}
	while (i >= 0 && i < 10);
		
	cout << "Expanded: " << textMsg << endl;
	
	return 0;
	}