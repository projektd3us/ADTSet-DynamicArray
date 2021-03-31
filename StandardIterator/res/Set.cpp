#include "Set.h"
#include "SetITerator.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


void Set::remPlace(int pos) { // function to remove item at pos in array
	for (int i = pos; i <= this->length - 2; i++) {
		this->arr[i] = this->arr[i + 1]; // shift right
	}
} // Best case: Theta(1), Worst Case: Theta(n) = Average Case, General Case: O(n)


Set::Set() {
	this->capacity = 100;
	this->length = 0;
	this->arr = (TElem*)malloc(100 * sizeof(TElem)); // does not use new, therefore realloc is ok
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
			this->arr = (TElem*)realloc(this->arr, newCapacity * sizeof(TElem)); // use of realloc is ok
			this->capacity = newCapacity;
		}
		this->arr[this->length] = elem; // add to set
		this->length++; // change element number
		return true;
	}
} // Best case: Theta(1) = Worst Case = Average Case = General Case


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

} // Best case: Theta(1), Worst Case: Theta(n) = Average Case, General Case: O(n)


bool Set::search(TElem elem) const {
	for (int i = 0; i <= this->length - 1; i++) {
		if (this->arr[i] == elem) {
			return true; // skip ahead
		}
	}
	return false; // nothing found
} // Best case: Theta(1), Worst Case: Theta(n) = Average Case, General Case: O(n)


int Set::size() const {
	return this->length;
} // All Cases: Theta(1)


bool Set::isEmpty() const {
	if (this->length == 0) {
		return true;
	}
	return false;
} // All Cases: Theta(1)


Set::~Set() {
	delete[] this->arr;
} // All Cases: Theta(1)


void Set::print() const
{
	for (int i = 0; i <= this->length - 1; i++) {
		cout << this->arr[i] << " ";
	}
} // personal helping function, Theta(n)


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


