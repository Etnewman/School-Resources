/*
	Name: Ethan Newman
	Section: 1310 - 001
	Date: 09/18/2019
	Project: PROGRAM ONE - "RedBox Movies"
*/

#include "movie.h"
#include "movielibrary.h"
#include "text.h"
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{

int numRedBox, choice;
char* filename = new char[10000];



cout << "\nHow many movies can this RedBox hold?";
cout << " Please enter in an integer greater than 0.\n";

cin >> numRedBox;

MovieLibrary* redBox = new MovieLibrary(numRedBox);


do 
{
	cout << "\n\nWhat would you like to do? Choose a number between 1 and 6.\n";
	cout << "	1.	Load movies from a file.\n";
	cout << "	2.	Save movies to a file.\n";
	cout << "	3.	Add a movie.\n";
	cout << "	4.	Remove a movie.\n";
	cout << "	5.	Display all movies.\n";
	cout << "	6.	Remove ALL movies from this RedBox and end program.\n";
	cout << "CHOICE: ";
	cin.ignore();
	cin >> choice;
	
	while(choice < 1 || choice > 6)
		{
			cout << "\nOops!  That was an invalid choice.\n";
			cout << "CHOOSE 1-6:  ";
			cin >> choice;
		}
		
		switch(choice)
		{
			case 1:
					cout << "\n\nWhat is the name of the file that contains movies?\n";
					cin >> filename;
					redBox->loadMoviesFromFile(filename);
					break;
			case 2:
					cout << "\n\nWhat would you like to name this file?\n";
					cin >> filename;
					redBox->saveToFile(filename);
					break;
			case 3:
					redBox->addMovieToArray();
					break;
			case 4:
					redBox->removeMovieFromArray();
					break;
			case 5:
					redBox->displayMovies();
					break;
			case 6:
					delete[] redBox;
					return 0;
					break;
		}
	}	while(choice != 6);
	
		delete redBox;
		return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		