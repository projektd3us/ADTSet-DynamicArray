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
	this->capacity = 2;
	this->length = 0;
	this->arr = new TElem[capacity]; // does not use new, therefore realloc is ok
}


bool Set::add(TElem elem) {
	//check if exists
	if (this->search(elem)) {
		return false; // skip ahead
	}
	else {
		//if cap full realloc
		if (this->capacity == this->length) {
			if (capacity == 0) { // setting cap if 0 to 1
				capacity = 1;
			}
			else {
				capacity *= 2;
			}
			TElem* temp_arr = new TElem[this->capacity]; // creating new arr
			for (int i = 0; i <= this->length - 1; i++) { // copying arr contents
				temp_arr[i] = this->arr[i];
			}
			delete[] this->arr;
			this->arr = temp_arr;
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
		if (length == capacity / 2) { // decreasing size if equal
			capacity /= 2;
			TElem* temp_arr = new TElem[this->capacity]; // creating new arr
			for (int i = 0; i <= this->length - 1; i++) { // copying arr contents
				temp_arr[i] = this->arr[i];
			}
			delete[] this->arr;
			this->arr = temp_arr;
		}
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


