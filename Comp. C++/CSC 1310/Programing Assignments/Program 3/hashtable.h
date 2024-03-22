#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <iomanip>
#include "HashEntry.h"

using namespace std;

template<typename T>
class HashTable
{
	private:
		int tableSize;
		HashEntry<T>** hashArray;
		
	public:
	
	HashTable(int);
	~HashTable();
	T getValue(int);
	void putValue(int, T);
	void removeValue(int);
	void printHashTable();
};

template<typename T>
HashTable<T>::HashTable(int size)
{
	tableSize = size;
	hashArray = new HashEntry<T>*[tableSize];
	
	for (int i = 0; i < tableSize; i++)
	{
		hashArray[i] = NULL;
	}
}

template<typename T>
T HashTable<T>::getValue(int key)
{
	int bucketIndex = key % tableSize;
	if (hashArray[bucketIndex] == NULL)
	{
		return NULL;
	}
	else
	{
		HashEntry<T>* entry = hashArray[bucketIndex];
		while (entry != NULL && entry->getKey() != key)
		{
			entry = entry->getNext();
		}
		if (entry == NULL)
		{
			return NULL;
		}
		else
		{
			return entry->getValue();
		}
	}
}

template<typename T>
void HashTable<T>::putValue(int key, T temp)
{
	int bucketIndex = key % tableSize;
	
	if (hashArray[bucketIndex] == NULL)
	{
		hashArray[bucketIndex] = new HashEntry<T>(key, temp);
	}
	else
	{
		HashEntry<T>* entry = hashArray[bucketIndex];
		
		while (entry->getNext() != NULL)
		{
			entry = entry->getNext();
		}
		if (entry->getKey() == key)
		{
			entry->setValue(temp);
		}
		else
		{
			entry->setNext(new HashEntry<T>(key, temp));
		}
	}
}

template<typename T>
void HashTable<T>::removeValue(int key)
{
	HashEntry<T>* entry;
	HashEntry<T>* prevEntry;
	int bucketIndex = key % tableSize;
	if (hashArray[bucketIndex] != NULL)
	{
		prevEntry = NULL;
		entry = hashArray[bucketIndex];
		while (entry->getNext() != NULL && entry->getKey() != key)
		{
			prevEntry = entry;
			entry = entry->getNext();
		}
		if (entry->getKey() == key)
		{
			if (prevEntry == NULL)
			{
				HashEntry<T>* nextEntry = entry->getNext();
				delete entry;
				hashArray[bucketIndex] = nextEntry;
			}
			else
			{
				HashEntry<T>* next = entry->getNext();
				delete entry;
				prevEntry->setNext(next);
			}
		}
	}
}
	
template<typename T>
void HashTable<T>::printHashTable()
{
	cout << "-----------------------------------\n";
	
	for (int i = 0; i < tableSize; i++)
	{
		if (hashArray[i] != NULL)
		{
			HashEntry<T>* entry = hashArray[i];
			
			while (entry->getNext() != NULL)
			{
				cout << "BUCKET: " << i << "----->" << setw(8) << *(entry->getValue());
				cout << endl;
				entry = entry->getNext();
			}
			cout << "BUCKET: " << i << "----->" << setw(8) << *(entry->getValue());
			cout << "\n";
		}
		else
		{
			cout << setw(8) << "BUCKET: " << i << "\tNULL" << endl;
		}
		
		cout << "\n-----------------------------------\n\n";

	}
}
	

	
#endif
	



	
