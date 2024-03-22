/* 
		Title: Lab7.cpp
		Author: Ethan Newman
		Date: 2/28/2019
		Purpose: Gringot's Banking Menu
		
*/

#include <iostream>
using namespace std;

int DisplayMenuGetChoice()
{
int checkNum1 = 0;
int menuNum;
int switchNum;
while (checkNum1 == 0) {
	cout << "WELCOME TO GRINGOTT'S BANK!\n";
	cout << "Please choose on of the following options:\n";
	cout << "	1 - Enter Goblin Sick Days\n";
	cout << "	2 - Display Something Cool\n";
	cout << "	3 - End the Program\n\n";
	cout << "CHOICE: ";
	cin >> menuNum;
	
	if (menuNum == 1) {
	switchNum = 1;
	break;}
	
	else if (menuNum == 2) { 
	switchNum = 2; 
	break;}
	
	else if (menuNum == 3) {
	switchNum = 3; 
	break;}
	
	else {
	cout << "\nYou have entered an invalid number. Please try again\n"; 
	cin >> menuNum;}
	}
	return switchNum;
}
	
void GoblinSickDays ()
{
	int numGoblin, sickDays;
	cout << "How many Goblin tellers worked at Gringott's during each of the last three years?\n";
	cin >> numGoblin;
	
	int arrayGoblinSick[numGoblin*3] = {0};
	for (int g = 1; g <= numGoblin; ++g) {
		for (int y = 1; y <= 3; ++y) {
			
			cout << "How many sick days was Goblin " << g << " out for, during year " << y << " ?\n";
			cin >> arrayGoblinSick[y];
			sickDays = sickDays + arrayGoblinSick[y];
			
		}
	}

	
	
	
	cout << "\nThe " << numGoblin << " Goblins were out sick for a total of " << sickDays << " days during the last 3 years.\n";

}
		
void DisplayCoolMessage ()
{
	cout << " .----------------.  .----------------.  .----------------.  .-----------------. .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. " << endl;
	cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
	cout << "| |    ______    | || |  _______     | || |     _____    | || | ____  _____  | || |    ______    | || |     ____     | || |  _________   | || |  _________   | || |      _       | || |    _______   | |" << endl;
	cout << "| |  .' ___  |   | || | |_   __ \\    | || |    |_   _|   | || ||_   \\|_   _| | || |  .' ___  |   | || |   .'    `.   | || | |  _   _  |  | || | |  _   _  |  | || |     | |      | || |   /  ___  |  | |" << endl;
	cout << "| | / .'   \\_|   | || |   | |__) |   | || |      | |     | || |  |   \\ | |   | || | / .'   \\_|   | || |  /  .--.  \\  | || | |_/ | | \\_|  | || | |_/ | | \\_|  | || |     \\_|      | || |  |  (__ \\_|  | |" << endl;
	cout << "| | | |    ____  | || |   |  __ /    | || |      | |     | || |  | |\\ \\| |   | || | | |    ____  | || |  | |    | |  | || |     | |      | || |     | |      | || |              | || |   '.___`-.   | |" << endl;
	cout << "| | \\ `.___]  _| | || |  _| |  \\ \\_  | || |     _| |_    | || | _| |_\\   |_  | || | \\ `.___]  _| | || |  \\  `--'  /  | || |    _| |_     | || |    _| |_     | || |              | || |  |`\\____) |  | |" << endl;
	cout << "| |  `._____.'   | || | |____| |___| | || |    |_____|   | || ||_____|\\____| | || |  `._____.'   | || |   `.____.'   | || |   |_____|    | || |   |_____|    | || |              | || |  |_______.'  | |" << endl;
	cout << "| |              | || |              | || |              | || |              | || |              | || |              | || |              | || |              | || |              | || |              | |" << endl;
	cout << "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
	cout << " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << endl;	
}


int main ()
{
	int checkNum2 = 0;
	int counterNum = 0;
	while (checkNum2 == 0) {
	int switchNum = DisplayMenuGetChoice();
	
	switch(switchNum){
	case 1: GoblinSickDays();
			break;
	case 2: DisplayCoolMessage();
			counterNum = counterNum + 1;
			break;
	case 3: cout << "You chose to display the cool message " << counterNum << " times.\n\n";
			cout << "Bye!";
			return 0;
			break;
	default: cout << "/nThis should never display!/n";
		}
	}
	return 0;
}