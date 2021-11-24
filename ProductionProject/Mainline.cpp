#include "Production.h"


int main()
{
	Production p;
	p.generateLottery();
	bool rangeCheck = p.checkRange();
	bool dupCheck = p.checkDuplicates();
	return 0;
}
