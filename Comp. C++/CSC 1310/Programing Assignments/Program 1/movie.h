#ifndef MOVIE_H
#define MOVIE_H

#include <fstream>
#include "Text.h"

using namespace std;


	class Movie
	{
		private:
			Text* movieTitle;
			int movieYear;
			Text* movieGenre;
			Text* movieRating;
			float movieNumStars;
			
		public:
			void printMovieDetails();
		
			void printMovieDetailsToFile(ofstream& filename);
			
			Text* getMovieTitle();

			
			Movie(Text*, int, Text*, Text*, float);
			~Movie();
	};
#endif