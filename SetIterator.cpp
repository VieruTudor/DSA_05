#include "SetIterator.h"
#include "Set.h"
#include <exception>
using namespace std;
SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
	if (set.isEmpty())
	{
		currentHashKey = -1;
		currentValue = 0;
	}
	else
	{
		currentHashKey = 0;
		while (currentHashKey < set.capacity && set.table[currentHashKey] == nullptr)
			currentHashKey++;
		currentValue = set.table[currentHashKey];
	}
}

/*
Best case : Theta(1) ?
Worst case : Theta(n)
Average case : Theta(n)
*/
void SetIterator::first() {
	//TODO - Implementation
	if (set.isEmpty())
	{
		throw exception();
	}
	currentHashKey = 0;
	while (set.table[currentHashKey] == nullptr)
		currentHashKey++;
	currentValue = set.table[currentHashKey];
}

/*
Best case : Theta(1) ?
Worst case : Theta(n)
Average case : Theta(n)
*/
void SetIterator::next() {
	//TODO - Implementation
	if (currentHashKey == -1 || currentValue == nullptr)
		throw exception();
	currentValue = currentValue->next;
	if (currentValue == nullptr)
	{
		currentHashKey++;
		while (currentHashKey < set.capacity && set.table[currentHashKey] == nullptr)
			currentHashKey++;
		if (currentHashKey == set.capacity)
			currentHashKey = -1;
		else
		{
			currentValue = set.table[currentHashKey];
		}
	}
}

/// Theta(1)
TElem SetIterator::getCurrent()
{
	//TODO - Implementation
	if (currentHashKey == -1)
		throw exception();
	return currentValue->value;
}

/// Theta(1)
bool SetIterator::valid() const {
	//TODO - Implementation
	return currentHashKey != -1 && currentValue != nullptr;
}



