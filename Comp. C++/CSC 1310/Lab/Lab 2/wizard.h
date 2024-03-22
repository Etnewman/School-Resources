#ifndef WIZARD_H
#define WIZARD_H
#include <iostream>

using namespace std;

class Wizard
{
	private:
		string nameWizard;
		int ageWizard;
		int heightWizard; //in whole inches
		
	public:
		Wizard(string, int, int);
		
		friend ostream & operator << (ostream& os, const Wizard& w)
		{
			os << "\n" << w.nameWizard << ", " << w.ageWizard << ", years old, " << w.heightWizard << " inches tall";
			return os;
		}
};

	Wizard::Wizard(string name, int age, int height)
	{
		nameWizard = name;
		ageWizard = age;
		heightWizard = height;
	}

#endif