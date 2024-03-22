/*
	Title: Program2.cpp
	Author: Ethan Newman
	Date: 3/12/2019
	Purpose: Ambition & Avarice
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <fstream>
using namespace std; 

void getPlayersName(string playerName[], int numPlayer);
int rollDice(string playerName);
void playerFinishedBoard(string playerName[], int playerMoney[], int boardSpace[], int numPlayer);
void activateActionSpace (string playerName[], int playerMoney[], int boardSpace[], int i);

int main()
{
	const int maxNumPlayer = 20;
	const int numSpaceBoard = 25;;
	int numPlayer;
	int whileCheck1 = 0;
	int whileCheck2 = 0;
	int whileCheck3 = 0;
	int whileCheck4 = 0;
	char playAgain;
	
	
	while (whileCheck1 == 0) {
	
	
	int boardSpace[25];
	string playerName[20];
	int playerMoney[20];

	for (int j = 0; j < numSpaceBoard; j++) {
		boardSpace[j] = 0;
	}
	
	for (int k = 0; k < maxNumPlayer; k++) {
		playerName[k] = " ";
		playerMoney[k] = 0;
	}

	cout << "Welcome, to AMBITION & AVARICE!" << endl;
		
	do {
	
		cout << "How many adventurers are there? ";
		cin >> numPlayer;
		
			if (numPlayer > maxNumPlayer || numPlayer <= 0) {
				
				cout << "You have entered a number past the maximum amount of allowed adventures. The max is 20.\n" << endl;
				cin.get();
				
			}
			else {
				
				break;
				
			}
	} while (whileCheck2 == 0);
	
	
	
	getPlayersName(playerName, numPlayer);



	do  {
		
		for (int i = 0; i < numPlayer; i++) {
			
			int diceRNG = rollDice(playerName[i]);
			
			boardSpace[i] += diceRNG;
			
				if (boardSpace[i] <= 25) {
					
					boardSpace[i] == 25;
					
				}
			
			activateActionSpace(playerName, playerMoney, boardSpace, i);
			 
			 cout << "\n" << playerName[i] << ", you have $" << playerMoney[i] << " in your coinpurse!\n\n";
			 cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
		
		
			if (boardSpace[i] >= numSpaceBoard) {
					
				playerFinishedBoard(playerName, playerMoney, boardSpace, numPlayer);
				whileCheck3 = 1;
				break;
				
				}
		
		
		
		} 
	} while (whileCheck3 == 0);
	
	
	do {
		
		cin.ignore();
		cout << "\n\nWould you like to play again?(Y/N): ";
		cin >> playAgain;
	
			if (playAgain == 'Y' || playAgain == 'y') {
			
				cout << "\nYou chose to play again!!\n\n";
				break;
		}
			else if (playAgain == 'N' || playAgain == 'n') {
			
				cout << "\n\nYou have chose to end the Program! \nGoodbye!";
				return 0;
			
		}
			else {
			
					cout << "\nYou have entered an invalid input. Try again.\n";
			cin.get();
		}
		
	} while (whileCheck4 == 0);
	
	}
return 0;
}

void getPlayersName(string playerName[], int numPlayer) 
{
	for (int i = 0; i < numPlayer; i++) {
	
		cin.ignore();
		cout << "Adventurer " << i+1 << ", please enter your name." << endl;
		getline(cin, playerName[i]);
	}
}

int rollDice(string playerName)
{
	int diceRNG;
	
	
	srand(time(0));
	diceRNG = rand()% 6 + 1;
	
	cout << "\n" << playerName << ", PRESS ENTER TO ROLL DIE." << endl;
	cin.get();
	cout << "YOU ROLLED A " << diceRNG << "." << endl;
	
		switch(diceRNG)
		{
	case 1:
			cout << " _________\n";
			cout << "|         |\n";
			cout << "|    o    |\n";
			cout << "|         |\n";
			cout << "|_________|\n\n";
		break;
	case 2:
			cout << " _________\n";
			cout << "|         |\n";
			cout << "|  o      |\n";
			cout << "|      o  |\n";
			cout << "|_________|\n\n";
		break;
	case 3:
			cout << " _________\n";
			cout << "| o       |\n";
			cout << "|    o    |\n";
			cout << "|       o |\n";
			cout << "|_________|\n\n";
		break;
	case 4:
			cout << " _________\n";
			cout << "| o     o |\n";
			cout << "|         |\n";
			cout << "| o     o |\n";
			cout << "|_________|\n\n";
		break;
	case 5:
			cout << " _________\n";
			cout << "| o     o |\n";
			cout << "|    o    |\n";
			cout << "| o     o |\n";
			cout << "|_________|\n\n";
		break;
	case 6:
			cout << " _________\n";
			cout << "| o     o |\n";
			cout << "| o     o |\n";
			cout << "| o     o |\n";
			cout << "|_________|\n\n";
		break;
		}
		return diceRNG;
	}	
	
void playerFinishedBoard(string playerName[], int playerMoney[], int boardSpace[], int numPlayer)
{
	float temp = 0;
	string posTemp;
	
		for (int i = 0; i < numPlayer; i++) {
			
		if (boardSpace[i] >= 25) {
			
			cout << "Adventurer who cleared this dungeon : " << playerName[i] << " Congratulations!!! " << endl;
		}
	
		if (playerMoney[i] > temp) {
			
			temp = playerMoney[i];
			posTemp = playerName[i];
		}
	}
	cout << "The adventurer that collected the most money is : " << posTemp << " with $" << temp << ", wow!!!" << endl;
}
	
void activateActionSpace (string playerName[], int playerMoney[], int boardSpace[], int i)
{
	int goodBadRNG, readFileRNG, moneyRNG;
	int j = 0;
	string line;
	cin.ignore();
	
	srand(time(0));
	goodBadRNG = rand() % 2+1;
	
	if (boardSpace[i] <= 25) {
					
		boardSpace[i] == 25;
					
	}
	
	cout << playerName[i] << ", you are on tile " << boardSpace[i] << endl << endl;
	
		if (goodBadRNG == 1) {
			
			ifstream myfile ("Good.txt");
			
			cout << "Lucky!!" << endl;
			
			cout << "\n    .-\"\"\"\"\"\"-." << endl;
			cout << "  .'          '." << endl;
			cout << " /   O      O   \\" << endl;
			cout << ":                :" << endl;
			cout << "|                |" << endl;
			cout << ": ',          ,' :" << endl;
			cout << " \\  '-......-'  /" << endl;
			cout << "  '.          .'" << endl;
			cout << "    '-......-'\n" << endl;
			
			
			if (myfile.is_open()) {
			
			srand(time(0));
			readFileRNG = rand() % 20+1;
					
					while (getline(myfile, line)) {
						 
						j++;
						 
						if (j == readFileRNG){

							cout << line << endl;
							
							srand(time(0));
							moneyRNG = rand() % 100000 + 1;
							
							playerMoney[i] += moneyRNG;
						}
					}
			myfile.close();
		}
		
		else {
			cout << "Unable to open file" << endl;
		}
		}
	
	
	if (goodBadRNG == 2) {
			
			ifstream myfile ("Bad.txt");
			
			cout << "Unlucky!!" << endl;
			
			cout << "\n     .-\"\"\"\"\"\"-." << endl;
			cout << "   .'          '." << endl;
			cout << "  /   O      O   \\" << endl;
			cout << " :           `    :" << endl;
			cout << " |                |" << endl;
			cout << " :    .------.    :" << endl;
			cout << "  \\  '        '  /" << endl;
			cout << "   '.          .'" << endl;
			cout << "     '-......-'\n" << endl;
			
			if (myfile.is_open()) {
			
				srand(time(0));
				readFileRNG = rand() % 20+1;
					
					while (getline(myfile, line)) {
						 
						 j++;
						 
						if (j == readFileRNG){

							cout << line << endl;
							
							srand(time(0));
							moneyRNG = rand() % 100000 + 1;
							
							playerMoney[i] -= moneyRNG;
							
						}
					}
			myfile.close();
	
			}
		else {
			cout << "Unable to open file" << endl;
	}
	}
}

