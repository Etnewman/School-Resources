#include <iostream>
#include <vector>
using namespace std;

void getStudentData(vector<int>&);
void sort(vector<int>&);
void print(vector<int>&);
double getAverage(vector<int>&);
double getMedian(vector<int>&);
int getMode(vector<int>&);

int main()
{
	double avg = 0;
	double median = 0;
	
	vector<int> vec;
	
	getStudentData(vec);
	
	sort(vec);
	
	print(vec);
	
	avg = getAverage(vec);
	
	median = getMedian(vec);
	
	cout << "\n\n\tNETFLIX STATISTICS\n";
	cout << "Average: " << avg << endl;
	cout << "Median: " << median << endl;
	
	return 0;
	
}

void getStudentData(vector<int>& vec)
{
	int temp = 0;
	int i = 0;
	cout << "\nEnter the number of hours each student spent on Netflix.\n";
	cout << "Enter -1 to end data entry.\n";
	
	do
	{
		cout << "Student " << i+1 << " : ";
		cin >> temp;
		while (temp < -1)
		{ 
			cout << "\nOOPS! Your number must be positive or 0.\n";
			cin >> temp;
		}
		if (temp == -1)
			break;
		cout << endl;
		vec.push_back(temp);
		i++;
	}while(vec[i-1] != -1);
		
}

void sort(vector<int>& vec)
{
	int key;
	int j;
	int size = vec.size();
	
	cout << "\nSorting the array with the Insertion Sort algorithm.\n\n";
	
	for (int i = 1; i < size; i++)
	{
		key = vec[i];
		j = i - 1;
		while (j >= 0 && vec[j] > key)
		{
			vec[j+1] = vec[j];
			j = j - 1;
		}
		vec[j+1] = key;
	}
}

void print(vector<int>& vec)
{
	int j = vec.size();
	
	cout << "Hours each student spent on Netflix: ";
	
	for (int i = 0; i < j; i++)
	{
		cout << vec[i] << "  ";
	}
}

double getAverage(vector<int>& vec)
{
	if (vec.size() == 0)
	{
		cout << "\nOOPS! You have an empty Vector!\n";
		return 0;
	}
	else
	{
		
		int j = vec.size();
		int sum = 0;
		double avg;
	
		for (int i = 0; i < j; i++)
		{
			sum += vec[i];
		}	
	
		avg = sum / j;
	
		return avg;
	}
}

double getMedian(vector<int>& vec)
{
	double median;
	int size = vec.size();
	if (vec.size() == 0)
	{
		cout << "\nOOPS! You have an empty Vector!\n";
		return 0;
	}
	else
	{
		if (size % 2 == 0)
		{
			median = (vec[size / 2 - 1] + vec[size / 2]) / 2;
		}
		else
		{
			median = vec[size / 2];
		}
	}
}
