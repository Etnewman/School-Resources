#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>

using namespace std;

class Weapon
{
	private:
		int idNum;
		string type;
		string name;
		string material;
		string description;
		int efficiency;
		
	public:
		Weapon(int i, string t, string n, string m, string d, int e)
		{
			idNum = i;
			type = t;
			name = n;
			material = m;
			description = d;
			efficiency = e;
		}
	
		string getType()
		{
			return type;
		}
		
		string getName()
		{
			return name;
		}
		
		string getMaterial()
		{
			return material;
		}
		
		string getDescription()
		{
			return description;
		}
		
		int getEfficiency()
		{
			return efficiency;
		}
};