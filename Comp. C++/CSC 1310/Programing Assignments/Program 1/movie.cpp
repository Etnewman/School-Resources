#include "movie.h"
#include "Text.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

Text* Movie::getMovieTitle()
{
	return movieTitle;
}


void Movie::printMovieDetails()
{
	
	cout << "\tMovie Title: \t\t";
	movieTitle->displayText();
	
	cout << "\n\tMovie Year: \t\t" << movieYear;
	
	cout << "\n\tMovie Genre: \t\t";
	movieGenre->displayText();
	
	cout << "\n\tMovie Rating: 	4	";
	movieRating->displayText();
	
	cout << "\n\tMovie IDMB Stars: " << movieNumStars;
	cout << endl;
}

void Movie::printMovieDetailsToFile(ofstream& temp)
{
	char cstring[1000];
		
	strncpy(cstring, movieTitle->getText(), 1000); 
	
	temp << cstring;
	temp << movieYear;
	
	strncpy(cstring, movieGenre->getText(), 1000);
	
	temp << cstring;
	
	strncpy(cstring, movieRating->getText(), 1000);
	
	temp << cstring;
	temp << movieNumStars;
	

}

Movie::Movie(Text* t, int y, Text* g, Text* r, float s)
{
	movieTitle = t;
	movieYear = y;
	movieGenre = g;
	movieRating = r;
	movieNumStars = s;
}

Movie::~Movie()
{
	delete[] movieTitle;
	delete[] movieGenre;
	delete[] movieRating;
}