#ifndef CAT_H
#define CAT_H
#include <iostream>

using namespace std;

class Cat
{
	private:
		string catName;
		string catBreed;
		string catColor;
		int catAge;
		
	public:
		Cat(string, string, string, int);
		
		friend ostream & operator << (ostream& os, const Cat& c)
		{
			os << "\n" << c.catName << ", " << c.catBreed << ", " << c.catColor << ", " << c.catAge;
			return os;
		}
};


	Cat::Cat(string name, string breed, string color, int age)
	{
		catName = name;
		catBreed = breed;
		catColor = color;
		catAge = age;
	}
#endif