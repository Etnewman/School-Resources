#include "course.h"

Course* createCourse(string name, string location, int numHours, int numSections)
{
	Course* tempCourse;
	tempCourse = new Course;
	
	tempCourse->name = name;
	tempCourse->location = location;
	tempCourse->numHours = numHours;
	tempCourse->numSections = numSections;
	
	return tempCourse;
}

void destroyCourse(Course* myCourses)
{
	
		delete [] myCourses->sections;
		delete [] myCourses;
	
}

void printCourse(Course* myCourse)
{
	
	cout << endl;
	cout << "COURSE NAME::               " << myCourse->name << endl;
	cout << "COURSE LOCATION:            " << myCourse->location << endl;
	cout << "COURSE HOURS:               " << myCourse->numHours << endl;
	cout << "COURSE SECTIONS:    " << endl;
	
		for (int i = 0; myCourse->numSections > i; i++)
		{
			cout << "                            " << *myCourse->sections << endl;
		}
}
