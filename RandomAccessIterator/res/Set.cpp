#include "Set.h"
#include "SetITerator.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


void Set::remPlace(int pos) { // function to remove item at pos in array
	for (int i = pos; i <= this->length - 2; i++) {
		this->arr[i] = this->arr[i + 1]; // shift right
	}
}


Set::Set() {
	this->capacity = 100;
	this->length = 0;
	this->arr = (TElem*)malloc(100 * sizeof(TElem));
}


bool Set::add(TElem elem) {
	//check if exists
	if (this->search(elem)) {
		return false; // skip ahead
	}
	else {
		//if cap full realloc
		if (this->capacity == this->length) {
			int newCapacity = this->capacity * 2;
			this->arr = (TElem*)realloc(this->arr, newCapacity * sizeof(TElem));
			this->capacity = newCapacity;
		}
		this->arr[this->length] = elem; // add to set
		this->length++; // change element number
		return true;
	}
}


bool Set::remove(TElem elem) { // fakes removal by shortening length
	int pos = -1; //untouchable
	for (int i = 0; i <= this->length - 1; i++) {
		if (this->arr[i] == elem) {
			pos = i; // skip ahead
			break;
		}
	}
	if (pos == -1) { // not found
		return false;
	}
	else { // found
		remPlace(pos); //remove
		this->length--; //count as removed
		return true; //exit with true
	}

}


bool Set::search(TElem elem) const {
	for (int i = 0; i <= this->length - 1; i++) {
		if (this->arr[i] == elem) {
			return true; // skip ahead
		}
	}
	return false; // nothing found
}


int Set::size() const {
	return this->length;
}


bool Set::isEmpty() const {
	if (this->length == 0) {
		return true;
	}
	return false;
}


Set::~Set() {
	delete[] this->arr;
}

void Set::print() const
{
	for (int i = 0; i <= this->length - 1; i++) {
		cout << this->arr[i] << " ";
	}
}


SetIterator Set::iterator(int firstPos, int step) const {
	return SetIterator(*this, firstPos, step);
}

SetIterator Set::iterator() const {
	return SetIterator(*this);
}

