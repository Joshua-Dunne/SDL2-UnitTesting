#include <set>
#include <stdlib.h>

class Production{
public:
	void generateLottery();
	bool checkRange();
	bool checkDuplicates();

	std::set<int> genSet;
};
