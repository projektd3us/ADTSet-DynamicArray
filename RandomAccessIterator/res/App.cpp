#include "Set.h"
#include "SetIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <stack>
#include <iostream>
using namespace std;




int main() {
	cout << "<<<< running RIT version" << endl;
	testAll(); // this is supposed to test iterator
	testAllExtended();



	cout << "That's all!" << endl;
	system("pause");

}



