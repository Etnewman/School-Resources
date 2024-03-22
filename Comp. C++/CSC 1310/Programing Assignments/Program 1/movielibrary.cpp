#include "movielibrary.h"
#include "text.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void MovieLibrary::resizeMovieArray()
{
	int max = maxMovies * 2;
	
	Movie** newMovieArray = new Movie*[max];

	
	for(int x = 0; x < numMovies; x++)
	{
		newMovieArray[x] = moviesArray[x];
	}
	
	delete	[] moviesArray;
	moviesArray = newMovieArray;
	maxMovies = max;
}

void MovieLibrary::addMovieToArray()
{
	char temp[10000];
	int year;
	float starRating;

	
	if(numMovies == maxMovies)
		resizeMovieArray();
	
	cout << "\n\nWhat is the name of the movie?\n";
	cin.ignore();
	cin.getline(temp, 10000);
	Text* name = new Text(temp);
	
	cout << "\nWhat year was this movie made?\n";
	cin >> year;
	
	cout << "\nWhat is the genre?\n";
	cin.ignore();
	cin.getline(temp, 10000);
	Text* genre = new Text(temp);
	
	cout << "\nWhat is the rating of the movie?\n";
	cin.getline(temp,10000);
	Text* rating = new Text(temp);
	
	cout << "\nWhat is the IMDB star rating?\n";
	cin >> starRating;
	
	Movie* oneMovie = new Movie(name, year, genre, rating, starRating);
	
	moviesArray[numMovies] = oneMovie;
	
	numMovies++;
}

void MovieLibrary::removeMovieFromArray()
{
	int movieToDelete; 

	if(numMovies == 0)
	{
		cout << "\nThere must be at least 1 movie to remove.\n";
	}
	else
	{
		cout << "\n\n";
		displayMovieTitles();
	
		cout << "\n\nWhich movie would you like to remove?\nEnter a number from the list of movies above.\n";
		cin >> movieToDelete;
	
		int index = movieToDelete-1;
	
		cout << endl;
		moviesArray[index]->getMovieTitle()->displayText();
		cout << " has been removed.\n\n";
	
		//Farzana and I couldn't get the program to work using the delete funciton
	
		moviesArray[index] = NULL;
	
		int numMoveBack = numMovies - 1;
	
		for(int x = index; x < numMoveBack; x++)
		{
			moviesArray[x] = moviesArray[x+1];
		}

		numMovies--;	

	}
	
}

void MovieLibrary::displayMovies()
{
	for (int x = 0; x<numMovies; x++)
	{
		moviesArray[x]->printMovieDetails();
	}
}

void MovieLibrary::displayMovieTitles()
{
	for (int x = 0; x<numMovies; x++)
	{
		cout << "	" << x+1 << ".	";
		cout << moviesArray[x]->getMovieTitle()->getText();
		cout << endl;
	}
}

void MovieLibrary::saveToFile(char* filename)
{
	ofstream outfile;
	outfile.open(filename);
	
	for (int x = 0; x<numMovies; x++)
	{
		moviesArray[x]->printMovieDetailsToFile(outfile);
	}
	outfile.close();
	
}

void MovieLibrary::loadMoviesFromFile(char* filename)
{
	ifstream inFile;
	inFile.open(filename);
	if(inFile.good())
	{
		Text* name;
		int year;
		Text* genre;
		Text* rating;
		float numStars;
		char temp[100];
		char temp2[100];
		
		inFile.getline(temp, 100);
		while(!inFile.eof())
		{
			if(numMovies == maxMovies)
				resizeMovieArray();
			
			name = new Text(temp);
			
			inFile >> year;
			inFile.ignore();
			
			inFile.getline(temp,100);
			genre = new Text(temp);
			
			inFile.getline(temp,100);
			rating = new Text(temp);
			
			
			inFile >> numStars;

			Movie* oneMovieItem = new Movie(name, year, genre, rating, numStars);
			
			moviesArray[numMovies] = oneMovieItem;
			
			moviesArray[numMovies]->getMovieTitle()->displayText();
			cout << " Was added to the Array.\n";
			numMovies++;	

			
			inFile.ignore();
			inFile.getline(temp, 100);
			
		}
	cout << "\n\nAll moves from " << filename << " have been added.\n";
	}
	else{
		cout << "\n\nI'm sorry, that file doesn\'t exist.\n\n";
	}
}


MovieLibrary::MovieLibrary(int max)
{
	
	moviesArray = new Movie*[max];
	numMovies = 0;
	maxMovies = max;
}

MovieLibrary::~MovieLibrary()
{
	for (int x = 0; x < numMovies; x++)
	{
		delete moviesArray[x];
	}
	
	delete[] moviesArray;
}
	



	
	
	