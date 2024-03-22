/*
	Title: Lab6.cpp
	Author: Ethan Newman && Austin Bohannon
	Date: 2/21/2019
	Purpose: RNG Game
*/

#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std; 

int main()
{
int checkNum1 = 0;
int checkNum2 = 0;
int checkNum3 =0;
int counterNum = 0;
int numGuess, rngNum;
char playCheck;
srand(time(0));
rngNum = rand() % 101+1;
	
	cout << "Are you ready to play? (y/n)  ";
	cin >> playCheck;
	
	while (checkNum1 == 0) {
		
		if (playCheck == 'n' || playCheck == 'N') {
			cout << "\nYou have decided to quit. To play, run the program again.";
			return 0; }
		else if (playCheck == 'y' || playCheck == 'Y') {
			while ( checkNum2 == 0) {
				
				cout << "\n\nEnter your guess : ";
				cin >> numGuess;
				
			
					if (numGuess < 0 || numGuess > 100) {
						cout << "\nYou entered an invalid number. Chooses between 1 and 100."; }
						
					else if (rngNum < numGuess && rngNum != numGuess) {
						cout << "\nToo High";
						counterNum = counterNum + 1; }
						
					else if (rngNum > numGuess && rngNum != numGuess) {
						cout << "\nToo Low";
						counterNum = counterNum + 1; }
						
					else if (rngNum == numGuess){ 
						cout << "\nCorrect! You got it in " << counterNum << " tries!" << endl; 
						cout << "Are you ready to play again? (y/n) ";
						cin >> playCheck;
						
							while (checkNum3 == 0) {
								if (playCheck == 'n' || playCheck == 'N') {
									cout <<" \nYou have decided to quit. To play, run the program again.";
									return 0; }
									
								else if (playCheck == 'y' || playCheck == 'Y') {
									srand(time(0));
									rngNum = rand() % 101+1;
									break; }
									
								else {
									cout << "\nYou have entered an invalid answer. Please try again. (y/n) ";
									cin >> playCheck;}
									
									}
								}
							}
						}			
			else {
				cout << "\nYou have entered an invalid answer. Please try again. (y/n) ";
				cin >> playCheck;}
	}
	return 0;
}
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							
							