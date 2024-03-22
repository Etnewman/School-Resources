#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){

   int run = 1;
   char toggle = 'n';
   int shirts = 0;
   char fill = ' ';
   const double costT = 12.00;
   float discCost = 0.00;
   float totalCost = 0.00;
   string name = "";
   string output[10] = {
     "Number of Shirts",
     "Discount",
     "5-10",
     "10%",
     "11-20",
     "15%",
     "21-30",
     "20%",
     "31 or more",
     "25%"
   };



   while(run == 1){
     cout << fixed << setprecision(2);
     cout << "\n\n\nWelcome to 80sTees.com!!\n\n";
     cout << "All shirts are $" << costT << endl;
     cout << "\nWe offer quantity discounts as follows: \n" << endl;
     cout << setw(output[0].length() + 5) << output[0] << setw(output[1].length() + 5) << output[1] << endl;
     cout << setw(output[2].length() + 5) << output[2] << setw(output[3].length() + 17) << output[3] << endl;
     cout << setw(output[4].length() + 5) << output[4] << setw(output[5].length() + 16) << output[5] << endl;
     cout << setw(output[6].length() + 5) << output[6] << setw(output[7].length() + 16) << output[7] << endl;
     cout << setw(output[8].length() + 5) << output[8] << setw(output[9].length() + 11) << output[9] << endl;

     cout << "\nWhat is your full name (first & last)?" << endl << "NAME: ";
     cin.ignore();
     getline(cin, name);

     cout << endl << name << ", how many shirts would you like?" << endl << "NUMBER OF SHIRTS: ";
     cin >> shirts;

     if(shirts < 0 || shirts == 0){
       cout << "Invalid input:  Please run the program again and enter a non-negative integer";
       break;
     }
     else if (shirts < 5){
       discCost = costT;
       totalCost = shirts * discCost;
     }
     else if ( shirts > 4 && shirts < 11){
       discCost = costT * .90;
       totalCost =  shirts * discCost;
     }
     else if(shirts > 10 && shirts < 21){
       discCost = costT * .85;
       totalCost = shirts * discCost;
     }
     else if(shirts > 20 && shirts < 31){
       discCost = costT * .80;
       totalCost = shirts * discCost;
     }
     else if(shirts > 30){
       discCost = costT * .75;
       totalCost = shirts * discCost;
     }

     cout << "\n\n ----------------------------------------";
     cout << "\nBILL FOR:  " << name << endl;
     cout << "DISCOUNTED COST:  $" << discCost << " (per shirt)" << endl;
     cout << "TOTAL COST:  $" << static_cast<double>(totalCost) << endl;
  }
  return 0;
}
