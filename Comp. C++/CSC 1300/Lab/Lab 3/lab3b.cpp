/*
	Title: Lab3a.cpp
	Author: Ethan Newman
	Date: 1/31/2019
	Purpose: Painting a wall (input, calculations, output)
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	double wallHeight, wallWidth, wallArea, needPaint;
	const double paintCover = 350;
	
	
	cout << "Enter wall height (feet) : " << endl;
	cin >> wallHeight;
	
	cout << "Enter wall width (feet) : " << endl;
	cin >> wallWidth;
	
	wallArea = wallHeight * wallWidth;
	
	cout << "Wall area: " << wallArea << " square feet" << endl;;
	
	needPaint = wallArea / paintCover;
	
	cout << "Paint needed: " << needPaint << " gallons" << endl;
	
	cout << "Cans needed: " << round(needPaint) << " can(s)"  << endl;
	
	return 0;
}