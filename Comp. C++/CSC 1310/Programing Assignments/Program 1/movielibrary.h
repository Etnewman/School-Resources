#ifndef MOVIELIBRARY_H
#define MOVIELIBRARY_H

#include "Text.h"
#include "movie.h"

using namespace std;

	class MovieLibrary
	{
		private:
			Movie** moviesArray;
			int maxMovies;
			int numMovies;
			
		public:
			void resizeMovieArray();
			
			void addMovieToArray();
			
			void displayMovies();
			
			void displayMovieTitles();
			
			void loadMoviesFromFile(char*);
			
			void removeMovieFromArray();
			
			void saveToFile(char*);
			
			MovieLibrary(int);
			~MovieLibrary();
	};

#endif