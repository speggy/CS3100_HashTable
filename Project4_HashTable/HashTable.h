#pragma once
#include <iostream>
#include "Slot.h"
#include <cstdlib>

#define MAXHASH 1000

using namespace std;

template <class T>
class HashTable
{
public:
	// basic constructor 
	HashTable()
	{
		hashTable = new Slot<T>[MAXHASH]; // create an array of 1000 slots
		itemCount = 0;
	}

	~HashTable()
	{
		delete[] hashTable;
	}

	/*Insert a new value into the hash table*/
	bool insert(int key, T value, int &collisions)
	{
		return probe(key, value, collisions); // Let the probe function do all the heavy lifting here
	}

	/*Remove an item from the hash table. Does so by setting the type to a tombstone*/
	bool remove(int key)
	{
		bool searchResult = find(key, hashTable[key].getValue());
		if (searchResult)
		{
			hashTable[key].kill();
			return true;
		}
		else
		{
			return false;
		}
	}

	/*Find the desired value in the hash table. Returns false if the value was not found*/
	bool find(int key, T& value)
	{
		if (hashTable[key].isEmpty() || hashTable[key].isTombstone())
		{
			return false;
		}
		else
		{
			return probe(key, value, 0);
		}
	}

	/*Calculates the load factor*/
	float alpha()
	{
		return itemCount / MAXHASH;
	}

	/*Calculate the hash value*/
	int hash(int UID)
	{
		return UID % MAXHASH;
	}

	/*Used to probe the hash table*/
	bool probe(int key, T& value, int collisions)
	{
		//int randVal = rand();
		int current = 0;
		//randVal = randVal % MAXHASH;

		while (current < MAXHASH)
		{
			if (hashTable[key].isEmpty()) // Check if the index does not have a value in it, add a record if empty
			{
				hashTable[key] = Slot<T>(key, value);
				itemCount++;
				return true;
			}
			//else if (hashTable[key].getValue() == value)
			//{
			//	return true;
			//}
			else // increment collisions since the index was not empty 
			{
				current++;
				collisions++;
				key += current; // probe randomly 
			}
		}
		return false;
	}

	friend ostream& operator<<(ostream& os, const HashTable<T>& me)
	{
		for (int i = 0; i < MAXHASH; i++)
		{
			cout << me[i] << endl;
		}
	}

private:
	Slot<T> *hashTable;
	int itemCount;

};

