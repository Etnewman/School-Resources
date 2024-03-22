#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>

using namespace std;

struct Course
{
	string name;
	string location;
	string* sections;
	int numSections;
	int numHours;
};

Course* createCourse(string, string, int, int);
void destroyCourse(Course* myCourse);
void printCourse(Course* myCourse);

#endif