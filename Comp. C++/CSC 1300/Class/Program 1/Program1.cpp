/*
          File Name: mosquito.cpp (PROGRAM ONE)
		  Author: Ethan Newman
		  Date: January 24, 2019
		  Purpose: First programming assignment in C++ to demonstrate proper code formatting,
		  proper variable definitions, data types, input & output, relational
		  expressions, strings, and random number generation.
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
using namespace std; 

int main()
{
	int r_factor = 0;
	int check = 0;
	int age = 0;
	int rng;
	string name;
	char y_n, n, y;

	cout<< "------------------------------   MOSQUITOS   ------------------------------" << endl;
	cout<< "Female mosquitoes need human blood to develop fertile eggs and" << endl;
	cout<< "not just anyone's blood will do.  The quiz below will determine if" << endl;
	cout<< "you are an attractive meal for mosquitoes. " << endl;
	cout<< "Mosquitoes select their victims by evaluating scent, exhaled carbon" << endl;
	cout<< "dioxide, movement and the chemicals in a person's sweat.\n\n\n";
	
	cout<< "What is your name?" << endl;
	cout<< "NAME:";
	getline(cin,name);
	
	while (check == 0|| y_n == 0)
	{
	
	cout<< "------------------------------   LOCATION   -------------------------------" << endl;
	cout<< "Do you live in one of the 20 worst mosquito cities in the US?" << endl;
	cout<< "(http://www.orkin.com/press-room/20-worst-mostquito-cities-in-us/)" << endl;
	
	cout<< "ENTER y or n:"; 
	cin >> y_n;
	
	if (y_n == 'y') 
	{
		r_factor  = r_factor + 5;
		check = check + 1;
	}
	
	else if (y_n == 'n')
	{	
		r_factor =  r_factor + 0;
		check = check +1;
	}
	
	else
	{
		cout<< "You have entered an invalid answer.\n\n";
		check = 0;
	}
	
	if (check > 0)
	{
		break;
	}

	}
	
	while (check == 1|| y_n <= 110)
	{
	cout<< "-------------------------------    SCENT    -------------------------------" << endl;
	cout<< "Do you wear perfume/cologne or naturally smell like flowers?" << endl;
	
	cout<< "ENTER y or n:";cin >> y_n;
	
	if (y_n == 'y') 
	{
		r_factor  = r_factor + 5;
		check = check + 1;
	}
	
	else if (y_n == 'n')
	{	
		r_factor =  r_factor + 0;
		check = check +1;
	}
	
	else
	{
		cout<<"You have entered an invalid answer.\n\n";
		check = 0;
	}
	
	if (check > 0)
	{
		break;
	}

	}
	
	
	while (check == 2|| y_n <= 110)
	{
	cout<< "----------------------------   CARBON DIOXIDE   ---------------------------" << endl;
	cout<< "Do you emit a large quantity of carbon dioxide when you exhale?" << endl;
	
	cout<< "ENTER y or n:";cin >> y_n;
	
	if (y_n == 'y') 
	{
		r_factor  = r_factor + 5;
		check = check + 1;
	}
	
	else if (y_n == 'n')
	{	
		r_factor =  r_factor + 0;
		check = check +1;
	}
	
	else
	{
		cout<< "You have entered an invalid answer.\n\n";
		check = 0;
	}
	
	if (check > 0)
	{
		break;
	}

	}
	
	while (check == 3|| y_n <= 110)
	{
	cout<< "-------------------------------    SWEAT    -------------------------------" << endl;
	cout<< "Do you sweat more than most people?" << endl;
	
	cout<< "ENTER y or n:";cin >> y_n;
	
	if (y_n == 'y') 
	{
		r_factor  = r_factor + 5;
		check = check + 1;
	}
	
	else if (y_n == 'n')
	{	
		r_factor =  r_factor + 0;
		check = check +1;
	}
	
	else
	{
		cout<< "You have entered an invalid answer.\n\n";
		check = 0;
	}
	
	if (check > 0)
	{
		break;
	}

	}
	
	while (check == 4|| age == 0)
	{
	cout<< "-------------------------------     AGE     -------------------------------" << endl;
	cout<< "Do you wear perfume/cologne or naturally smell like flowers?" << endl;
	
	cout<< "ENTER your age:";cin >> age;
	
	if (age >= 6) 
	{
		r_factor  = r_factor + 25;
		check = check + 1;
	}
	
	else if (age <6 || age >= 12)
	{	
		r_factor =  r_factor + 20;
		check = check +1;
	}
	else if (age < 12 || age >= 19)
	{	
		r_factor =  r_factor + 15;
		check = check +1;
	}
	
	else if (age < 19)
	{	
		r_factor =  r_factor + 5;
		check = check +1;
	}
	
	else
	{
		cout<< "You have entered an invalid answer.\n\n";
		check = 0;
	}
	
	if (check > 0)
	{
		break;
	}

	}
	
	while (check == 5|| y_n <= 110)
	{
	cout<< "------------------------------  CHOLESTEROL  ------------------------------" << endl;
	cout<< "Do you have a high concentration of cholesterol on your skin surface?" << endl;
	
	cout<< "ENTER y or n:";cin >> y_n;
	
	if (y_n == 'y') 
	{
		r_factor  = r_factor + 5;
		check = check + 1;
	}
	
	else if (y_n == 'n')
	{	
		r_factor =  r_factor + 0;
		check = check +1;
	}
	
	else
	{
		cout<< "You have entered an invalid answer.\n\n";
		check = 0;
	}
	
	if (check > 0)
	{
		break;
	}

	}
	
	srand( time(0));
	rng = rand() % 50+1;
	r_factor = rng + r_factor;
	
	cout<< "----------------------------    RESULTS    -------------------------------" << endl;
	cout<< "Your lucky (or unlucky) number is "<< rng << "\n\n" ;
	cout<< "Mostquitoes can act as reservoirs of diseases such as West Nile virus," << endl; 
	cout<< "malaria, yellow fever and dengue fever.\n\n";
	cout<< name << ", you are " << r_factor << "% likely to contract one of these diseases.\n\n\n";
	cout<< "-------------------------------   THE END   -------------------------------";
	
	return 0;

}