#include "SetIterator.h"
#include "Set.h"
#include <exception>
using namespace std;

SetIterator::SetIterator(const Set& m) : set(m)
{
	this->current = 0;
}


void SetIterator::first() {
	this->current = 0;
}


void SetIterator::next() {
	if (!this->valid()) {
		throw exception();
	}
	else {
		this->current++;
	}
}


TElem SetIterator::getCurrent()
{
	if (!this->valid()) {
		throw exception();
	}
	return this->set.arr[this->current];
}

bool SetIterator::valid() const {
	if (this->current < this->set.length) {
		return true;
	}
	return false;
}



