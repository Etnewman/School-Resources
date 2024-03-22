//recursionPractice2.cpp

#include <iostream>
using namespace std;
void function(int);

int main()
{
	int x = 10;
	function(x);
	return 0;
}
void function (int num)
{
	if(num > 0)
	{
		for (int x=0; x<num; x++)
			cout << '*';
		cout << endl;
		function(num-1);
	}
}


