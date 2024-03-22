/*
	File Name: lab2a.cpp
	Author: Ethan Newman & Austin Bohannon
	Date: January 24, 2019
	Purpose: To calculate and display:
	The amount paid for the stock alone
	The amount of the commission
	The total amount paid
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	float amount_stock = 750;
	float amount_share = 35.00;
	float per_commission = .02;
	float stock_paid, amount_commission, total;
	
	stock_paid = amount_stock * amount_share;
	amount_commission = stock_paid * per_commission;
	total = amount_commission + stock_paid;
	
	cout << setprecision (2) << fixed;
	
	cout << "Amount paid for the stock : $" << stock_paid << endl;
	cout << "Commission paid on the sale : $" << per_commission << endl;
	cout << "total amount paid for stock : $" << total << endl;

	return 0;
}