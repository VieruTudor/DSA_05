#include "Set.h"
#include "SetITerator.h"
#include <cmath>
#include <iostream>
#include <cassert>
using namespace std;

int Set::h(TElem elem) const
{
	return abs(elem % capacity);
}



Set::Set() {
	//TODO - Implementation
	capacity = 10;
	hashSize = 0;
	table = new Node * [capacity];
	for (int i = 0; i < capacity; i++)
		table[i] = NULL;
	
}
// Theta(2 * capacity)
void Set::resize(int newCapacity)
{
	Node** newTable = new Node * [newCapacity];
	for (int i = 0; i < newCapacity; i++)
		newTable[i] = NULL;
	int oldCapacity = capacity;
	capacity = newCapacity;
	for (int i = 0; i < oldCapacity; i++)
	{
		Node* current = table[i];
		while (current != NULL)
		{
			auto previous = current;
			auto position = h(current->value);
			Node* newNode = new Node;
			newNode->next = newTable[position];
			newNode->value = current->value;
			newTable[position] = newNode;
			current = current->next;
			delete previous;
		}
	}
	delete[] table;
	table = newTable;

}

/*
Best case : Theta(1)
Worst case : Theta(2 * capacity)
Average case : Theta(n)
*/
bool Set::add(TElem elem) {
	//TODO - Implementation
	if (this->search(elem) == 1)
		return false;
	if ((float)hashSize / (float)capacity >= ALPHA)
		resize(2 * capacity);
	auto addPosition = h(elem);
	auto newNode = new Node;
	newNode->value = elem;
	newNode->next = table[addPosition];
	table[addPosition] = newNode;
	hashSize++;
	return true;
}

/*
Best case : Theta(1)
Worst case : Theta(n)
Average case : Theta(n)
*/
bool Set::remove(TElem elem) {
	//TODO - Implementation
	if (hashSize == 0)
		return false;
	auto current = table[h(elem)];
	Node* previous = NULL;
	bool exists = false;
	while (current != NULL)
	{
		if (current->value == elem)
		{
			if (previous == NULL)
			{
				table[h(elem)] = current->next;
			}
			else
			{
				previous->next = current->next;
				
			}
			hashSize--;
			exists = true;
			break;
		}
		previous = current;
		current = current->next;
	}
	return exists;
}
/*
Best case : Theta(1)
Worst case : Theta(n)
Average case : Theta(n)
*/
bool Set::search(TElem elem) const {
	//TODO - Implementation
	int searchPosition = h(elem);
	auto current = table[searchPosition];
	while (current != NULL)
	{
		if (current->value == elem)
			return true;
		current = current->next;
	}
	return false;

}

/// Theta(1)
int Set::size() const {
	//TODO - Implementation
	return hashSize;
}

/// Theta(1)
bool Set::isEmpty() const {
	//TODO - Implementation
	return hashSize == 0;
}


Set::~Set() {
	//TODO - Implementation
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}

/// Theta(n) - filter function
void Set::filter(Condition condition)
{
	auto it = this->iterator();
	it.first();
	while (it.valid())
	{
		TElem value = it.getCurrent();
		if (!condition(value))
		{
			this->remove(value);
		}
		it.next();
	}
}


