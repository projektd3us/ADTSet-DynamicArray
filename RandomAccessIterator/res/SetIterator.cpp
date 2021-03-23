#include "SetIterator.h"
#include "Set.h"
#include <exception>
using namespace std;

// default constructor
SetIterator::SetIterator(const Set& m) : set(m)
{
	this->firstPos = 0;
	this->current = 0;
	this->step = 1; // set step
}

SetIterator::SetIterator(const Set& m, int firstP, int stp) : set(m)
{
	this->firstPos = firstP;
	this->current = firstP;
	this->step = stp; // set step
}


void SetIterator::first() {
	this->current = this->firstPos; // set first pos of iterator to first pos of req iteration
}


void SetIterator::next() {
	if (!this->valid()) {
		throw exception();
	}
	else {
		this->current += this->step;
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
	if ((this->current < this->set.length)&& (this->current >= 0)) {
		return true;
	}
	return false;
}



