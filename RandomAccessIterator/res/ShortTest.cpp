#include "ShortTest.h"
#include <assert.h>
#include "Set.h"
#include "SetIterator.h"

#include <iostream>

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

	// positive step
	SetIterator it = s.iterator(0, 1);
	it.first();
	int sum = 0;
	while (it.valid()) {
		TElem e = it.getCurrent();
		sum += e;
		it.next();
	}
	assert(sum == 19);

	// negative step
	SetIterator itN = s.iterator(2, -1);
	itN.first();
	int sum2 = 0;
	while (itN.valid()) {
		TElem e2 = itN.getCurrent();
		sum2 += e2;
		itN.next();
	}
	assert(sum2 == 22);
}

