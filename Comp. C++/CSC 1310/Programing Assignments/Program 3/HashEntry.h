#ifndef HASHENTRY_H
#define HASHENTRY_H
#include <iostream>

using namespace std;

template<typename T>
class HashEntry
{
	private:
		int key;
		T value;
		HashEntry* next;
		
	public:
		HashEntry(int, T);
		int getKey();
		T getValue();
		HashEntry* getNext();
		void setNext(HashEntry*);
		void setValue(T);
};

template<typename T>
HashEntry<T>::HashEntry(int k, T temp)
{
	this->key = k;
	this->value = temp;
	this->next = NULL;
}

template<typename T>
int HashEntry<T>::getKey()
{
	return key;
}

template<typename T>
T HashEntry<T>::getValue()
{
	return value;
}

template<typename T>
HashEntry<T>* HashEntry<T>::getNext()
{
	return next;
}

template<typename T>
void HashEntry<T>::setNext(HashEntry* next)
{
	this->next = next;
}

template<typename T>
void HashEntry<T>::setValue(T temp)
{
	value = temp;
}

#endif