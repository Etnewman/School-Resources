#include<iostream>
#include<string>

using namespace std;

struct Player
{
	string name;
	string hometown;
	int age;
	int numGames;
	int totalHours;
};

int main ()
{
	int numPlayers;
	int max = 0;
	int min = 1000;
	
	cout << "\n\nHow many players are there in both the eSports club and CSC Major?" << endl;
	cin >> numPlayers;
	
	Player* playerArr;
	int** playerHours;
	
	playerArr = new Player[numPlayers];
	playerHours = new int*[numPlayers];
	
	for (int i = 0; i < numPlayers; i++)
	{
		cout << "\n\nPLAYER " << i+1 << ",";
		
		cin.ignore();
		cout << "\n\nNAME: ";
		getline(cin, playerArr[i].name);
		
		cout << "\nHOMETOWN: ";
		getline(cin, playerArr[i].hometown);
		
		cout << "\nAGE: ";
		cin >> playerArr[i].age;
		
		cout << "\nNUMBER OF GAMES PLAYED: ";
		cin >> playerArr[i].numGames;
		cin.ignore();
		
		playerHours[i] = new int[playerArr[i].numGames];
		
		playerArr[i].totalHours = 0;
		
		for (int x = 0; x < playerArr[i].numGames; x++)
		{
			cout << "\t" << playerArr[i].name << ", ENTER IN THE AMOUNT OF HOURS FOR GAME " << x+1 << ": ";
			cin >> playerHours[i][x];
			
			playerArr[i].totalHours += playerHours[i][x];
		}
		
		if(playerArr[i].totalHours > max)
			{
				max = playerArr[i].totalHours;
			}
		if (playerArr[i].totalHours < min)
			{
				min = playerArr[i].totalHours;
			}
	}

	for (int k = 0; k < numPlayers; k++)
	{
		if (playerArr[k].totalHours == max)
		{
			cout << endl << playerArr[k].name << " has the most total hours played with " << playerArr[k].totalHours << " hours.";
		}
		if (playerArr[k].totalHours == min)
		{
			cout << endl << playerArr[k].name << " has the least total hours played with " << playerArr[k].totalHours << " hours.";
		}
	}
	
	return 0;
	
}

