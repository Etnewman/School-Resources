#ifndef LEXO_H
#define LEXO_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Sorts the String array by length
void sortLength(string arr[], int count);

//helps vector use sort()
bool compare(string a, string b);

//displays permutated strings
void display(string arr[], int n);
#endif