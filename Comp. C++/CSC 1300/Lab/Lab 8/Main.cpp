/*
    Title: Main.cpp
    Date 03/14/2019
    Author: Parker Delbene/Darsh Dinger
    Purpose: Mathematics, File Input/Ouput, etc



*/
#include <iostream>
#include <cstdlib>
#include "Primes.h"

int main(){
  string printPrimes;
  ifstream fileName;
  int x;
  int y;

  fileName.open("Ranges.txt");

  cout << "What would you like to name the output file where the prime numbers will be printed to?" << endl;
  cout << "Include .txt at the end of filename" << endl;
  getline(cin, printPrimes);

  ofstream outfile (printPrimes.c_str());

  if(!fileName){
    cout << "Specified file could not be opened.\n Terminating program." << endl;
    return 0;
  }
  fileName >> x;
  fileName >> y;
  cout << x << y;
  findPrimes(x,y, printPrimes);

  cout << "The prime numbers in that range have been printed to Primes.txt";


return 0;
}
