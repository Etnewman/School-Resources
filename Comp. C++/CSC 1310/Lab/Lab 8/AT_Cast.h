#ifndef AT_CAST_H
#define AT_CAST_H
#include <iostream>
#include <string>

using namespace std;

class AT_Cast
{
	private:
		int castID;
		string name;

	public:
		AT_Cast(int c = 0, string m = "None")
		{
			castID = c;
			name = m;
		}
		
		void setID(int num)
		{
			castID = num;
		}
		
		void setName(string n)
		{
			name = n;
		}
		
		int getID()
		{
			return castID;
		}
		
		string getName()
		{
			return name;
		}
		
		bool operator < (const AT_Cast& member)
		{
			return this->castID < member.castID;
		}
		
		friend ostream &operator << (ostream &strm, AT_Cast &member)
		{
			strm << "Cast ID Number: " << member.castID;
			strm << "\tName: " << member.name << endl;
			return strm;
		}
};

#endif
		
		