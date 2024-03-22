#ifndef TRAIN_H
#define TRAIN_H
#include <iostream>

using namespace std;

template<typename T>
class Train
{
	private:
		string trainName;
		string homeTrain;
		int maxCapTrain;
		int currNumTrain;
		T* passArray;
		
	public:
		Train(string, string, int);
		~Train();
		
		string getTrainName();
		
		void printPassengers();
		
		void addPassenger(T);
};
	template<typename T>
	Train<T>::Train(string name, string home, int maxCap)
	{
		trainName = name;
		homeTrain = home;
		maxCapTrain = maxCap;
		
		currNumTrain = 0;
		
		passArray = new T[maxCap];
		
	}
	
	template<typename T>
	Train<T>::~Train()
	{
		delete [] passArray;
	}
	
	template<typename T>
	string	Train<T>::getTrainName()
	{
		return trainName;
	}
	
	template<typename T>
	void Train<T>::addPassenger(T temp)
	{
		
		if (currNumTrain >= maxCapTrain)
		{
			cout << "\nNo more passengers can enter the train" << endl;
		}
		else
		{
			passArray[currNumTrain] = temp;
			
			currNumTrain = currNumTrain + 1;
		}
	}
	
	template<typename T>			
	void Train<T>::printPassengers()
	{
		for (int x = 0; x < currNumTrain; x++)
		{
			cout << *(passArray[x]) << endl;
			
		}
	}
	
	#endif

