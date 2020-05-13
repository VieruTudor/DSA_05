#include "ShortTest.h"
#include <assert.h>
#include "Set.h"
#include "SetIterator.h"
#include <iostream>
using namespace std;

bool condition(int x)
{
	return x % 2 == 0;
}
void testAll() { 
	Set s;
	assert(s.isEmpty() == true);
	assert(s.size() == 0); 
	assert(s.add(5)==true);
	assert(s.add(1)==true);
	assert(s.add(10)==true);
	assert(s.add(7)==true);
	assert(s.add(1)==false);
	assert(s.add(10)==false);
	assert(s.add(-3)==true);
	assert(s.size() == 5);
	assert(s.search(10) == true);
	assert(s.search(16) == false);
	assert(s.remove(1) == true);
	assert(s.remove(6) == false);
	assert(s.size() == 4);


	SetIterator it = s.iterator();
	it.first();
	int sum = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		sum += e;
		it.next();
	}
	assert(sum == 19);

	auto itBeforeFilter = s.iterator();
	itBeforeFilter.first();
	cout << "\nBefore filter : ";
	while (itBeforeFilter.valid())
	{
		cout << itBeforeFilter.getCurrent() << " ";
		itBeforeFilter.next();
	}
	cout << "\nAfter filter : ";
	s.filter(condition);
	auto itAfterFilter = s.iterator();
	itAfterFilter.first();
	while (itAfterFilter.valid())
	{
		cout << itAfterFilter.getCurrent() << " ";
		itAfterFilter.next();
	}
	cout << "\n";
	
	

}

