#include <iostream>
#include <assert.h>

#include "../../Production/include/Production.h"

using namespace std;

int main()
{
	Production p;

	p.generateLottery();

	// check for 6 numbers
	assert(p.genSet.size() == 6);
	
	// check if 6 numbers are within range 1 - 46
	assert(p.checkRange());

	// check for no duplicates
	assert(p.checkDuplicates());

	cin.get();
}