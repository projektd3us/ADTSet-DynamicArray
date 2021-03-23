#pragma once
#include "Set.h"

class SetIterator
{
	//DO NOT CHANGE THIS PART
	friend class Set;
private:
	//DO NOT CHANGE THIS PART
	const Set& set;
	SetIterator(const Set& m, int firstP, int stp);
	SetIterator(const Set& m);

	int firstPos;
	int current; // curr pos of el in arr
	int step;

public:

	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};


