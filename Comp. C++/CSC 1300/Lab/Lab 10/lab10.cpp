/*
	Title: Lab10.cpp
	Author: Ethan Newman & Parker DelBene
	Date: 3/28/2019
	Purpose: Vector Moon Pies
*/

#include <iostream>
#include <vector>

using namespace std;

void enterStolenMoonPies(vector<double>& moonPieVector, double moonPiesDays);
double totalMoonPies(vector<double> moonPieVector, double moonPiesDays);
double averageMoonPies(double moonPiesDays, double sumMoonPies);
int highestMoonPies(vector<double> moonPieVector, double moonPiesDays);
int lowestMoonPies(vector<double> moonPieVector, double moonPiesDays);

int main() 
{
	double moonPiesDays = 0;
	double sumMoonPies = 0;
	double meanMoonPies = 0;
	int highestMoonPie = 0;
	int lowestMoonPie = 0;
	
	cout << "How many days did Jane steal moon pies?\n";
	
	cin >> moonPiesDays;
	
	vector<double> moonPieVector(moonPiesDays);
	
	enterStolenMoonPies(moonPieVector, moonPiesDays);
	
	sumMoonPies = totalMoonPies(moonPieVector, moonPiesDays);
	
	meanMoonPies = averageMoonPies(moonPiesDays, sumMoonPies);
	
	highestMoonPie = highestMoonPies(moonPieVector, moonPiesDays);
	
	lowestMoonPie = lowestMoonPies(moonPieVector, moonPiesDays);
	
	cout << "\n\n---------------RESULTS---------------\n";
	cout << "TOTAL # MOON PIES STOLEN :  " << sumMoonPies << endl;
	cout << "AVERAGE # MOON PIES STOLEN PER DAY :  " << meanMoonPies << endl;
	cout << "MOST # MOON PIES STOLEN IN ONE DAY:  " << highestMoonPie << endl;
	cout << "LEAST # MOON PIES STOLEN IN ONE DAY:  " << lowestMoonPie << endl;
	
	return 0;
	
}

void enterStolenMoonPies(vector<double>& moonPieVector, double moonPiesDays)
{
	cout << "\nEnter the number of moon pies stolen each day.";
	
	for (int i = 0; i < moonPiesDays; i++) {
		
		cout << "\nDay " << i+1 << ": ";
		cin >> moonPieVector.at(i);
	}
}

double totalMoonPies(vector<double> moonPieVector, double moonPiesDays)
{
	double sumPies = 0;
	
	for (int i = 0; i < moonPiesDays; i++) {
		
		sumPies += moonPieVector.at(i);
	}
	
	return sumPies;
}

double averageMoonPies(double moonPiesDays, double sumMoonPies)
{
	
	double avgPies = 0;
	
	avgPies = sumMoonPies / moonPiesDays;
	
	return avgPies;
}
	
int highestMoonPies(vector<double> moonPieVector, double moonPiesDays)
{
	int highPie = 0;
	
	for (int i = 0; i < moonPiesDays; i++) {
		
			if (moonPieVector.at(i) > highPie) {
				
					highPie = moonPieVector.at(i);
			}
	}
	
	return highPie;
}

int lowestMoonPies(vector<double> moonPieVector, double moonPiesDays)
{
	int lowPie = 100;
	
	for (int i = 0; i < moonPiesDays; i++) {
		
			if (moonPieVector.at(i) < lowPie) {
				
					lowPie = moonPieVector.at(i);
			}
	}
	
	return lowPie;
}
	
		



