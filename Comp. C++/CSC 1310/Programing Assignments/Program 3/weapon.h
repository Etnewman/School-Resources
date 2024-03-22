#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <string>

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
		Weapon(int i, string t, string n, string m, string d, float e)
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
		
		float getEfficiency()
		{
			return efficiency;
		}
		
		void setID(int temp)
		{
			idNum = temp;
		}
		
		void setType(string temp)
		{
			type = temp;
		}
		
		void setMaterial(string temp)
		{
			material = temp;
		}
		
		void setDescription(string temp)
		{
			description = temp;
		}
		
		void setEfficiency(float temp)
		{
			efficiency = temp;
		}

		void printWeapon()
		{
			cout << "\nID: " << idNum;
			cout << "\nWeapon type: " << type;
			cout << "\nWeapon name: " << name;
			cout << "\nWeapon material(s): " << material;
			cout << "\nBrief weapon description: " << description;
			cout << "\nWeapon efficiency rating from 1.0 - 10.0: " << efficiency;
			cout << endl << endl;	
		}
		
		friend ostream &operator << (ostream &strm, Weapon &wep)
		{
			strm << "ID: " << wep.idNum;
			strm << "\n\tWeapon type: " << wep.type;
			strm << "\n\tWeapon name: " << wep.name;
			strm << "\n\tWeapon material(s): " << wep.material;
			strm << "\n\tBrief weapon description: " << wep.description;
			strm << "\n\tWeapon efficiency rating from 1.0 - 10.0: " << wep.efficiency;
			return strm;
		}
};
		
#endif