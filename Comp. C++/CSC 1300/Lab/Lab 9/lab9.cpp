/*
	Title: Program2.cpp
	Author: Ethan Newman
	Date: 3/12/2019
	Purpose: Ambition & Avarice
*/

#include <iostream>
using namespace std;

int inputBarCode(int barCode[]);
void printBarCode(int barCode[], int barSize);
int sumOddDigits(int barCode[], int barSize);
int multiplyEvenDigits(int barCode[], int barSize);
bool compareCheckSum(int sumOddNum, int sumEvenNum, int barCode[], int barSize);

int main()
{
	int checkNum = 0;
	
	while( checkNum == 0) {
	
	char whileCheck;
	int barCode[20];
	int barSize = 0;
	int sumOddNum = 0;
	int sumEvenNum = 0;
	bool isCorrect;
	barSize = inputBarCode(barCode);
	
	printBarCode(barCode, barSize);
	
	sumOddNum = sumOddDigits(barCode, barSize);
	cout << sumOddNum << endl;
	
	sumEvenNum = multiplyEvenDigits(barCode, barSize);
	cout << sumEvenNum << endl;
	
	isCorrect = compareCheckSum( sumOddNum,  sumEvenNum,  barCode,  barSize);
	
		if (isCorrect == true) {
			cout << "\nThe barcode is CORRECT"; }
		else {
			cout << "\nThe barcode is INCORRECT"; }
			
			cout << "\nWould you like to run this program again?(Y/N)" << endl;
			
				cin >> whileCheck;
				
				if (whileCheck == 'y' || whileCheck == 'Y') {
				}
				else if (whileCheck == 'n' || whileCheck == 'N') {
					cout << "\nYou have decided to exit the program!.";
				return 0; }
				else {
					cout << "\nYou have entered an invalid answer. Try again.";
				cin >> whileCheck; }
	}
	return 0;
	
}

int inputBarCode(int barCode[])
{
	int barCodeNum;
	int size;
	
	cout << "\nEnter in the barcode with each number separated by a space. At the end, enter in -1.\n\n";
	
	
		for (int i = 0; i <= 20; i++) {
		
			cin >> barCodeNum;
		
				if (barCodeNum == -1) {
			
					barCode[i] = -1;
					size = i;
					break;
				}
				else {
			
					barCode[i] = barCodeNum;
				}
		}
		
		return size;
		
}

void printBarCode(int barCode[], int barSize) 
{
	
	cout << "\nThe barcode you entered is: ";
	
		for (int i = 0; i < barSize; i++) {
		
			cout << barCode[i] << " ";
		
		}
		
	cout << endl;
		
}

int sumOddDigits(int barCode[], int barSize)
{
	int numOdd = 0;
	
		for (int i = 0; i < barSize; i++) {
		
			if ( i % 2 != 0) {
				
				numOdd += barCode[i];
		
			}
		}
	
	return numOdd;
	
}

int multiplyEvenDigits(int barCode[], int barSize) 
{
	int tempArray[barSize];
	int temp = 0;
	int sumEvenNum = 0;
	
		for (int j = 0; j < barSize; j++) {
			
			tempArray[j] = 0; 
			
		}
	
	
		for (int i = 0; i < barSize; i++) {
	
			if ( i % 2 == 0) {
	
			tempArray[i] = barCode[i] * 2;
			
			
			
				if (tempArray[i] > 9) {
					
					temp = temp + (tempArray[i] - 9);
					
				
				}
				
				else {
					
					sumEvenNum = sumEvenNum + (tempArray[i] + temp);
				}
				

		}
		}
	return sumEvenNum;
	
}

bool compareCheckSum (int sumOddNum, int sumEvenNum, int barCode[], int barSize)
{
	int sumAll = 0;
	int checkNum = 0;
	
	sumAll = sumOddNum + sumEvenNum;
	
	checkNum = sumAll % 10;
	
	checkNum = 10 - checkNum;
	cout << checkNum << endl;
	
		if (checkNum == 10) {
			checkNum = 0; }

		if (checkNum == barCode[barSize-1]) {
		return true; }
		else	{
		return false; }
}
			
			
	
	
	
	
