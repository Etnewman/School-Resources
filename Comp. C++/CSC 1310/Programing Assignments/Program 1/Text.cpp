#include "text.h"
#include <iomanip>
#include <iostream>
#include <cstring>

using namespace std;

const char* Text::getText() const
{
	return textArray;
}

int Text::getLength()
{
	return textLength;
}

void Text::displayText()
{
	cout << textArray;
}

Text::Text(const char* text)
{	
	textLength = strlen(text);
	
	char* tempTextArray = new char[(textLength)+1];
	
	strcpy(tempTextArray, text); 
	
	this->textArray = tempTextArray;	
}

Text::~Text()
{
	delete [] textArray;
}