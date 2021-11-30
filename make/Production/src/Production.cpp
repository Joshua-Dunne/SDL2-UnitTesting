#include "../include/Production.h"

void Production::generateLottery()
{
	// clear any data that may exist before generation
	if (genSet.size() > 0)
		genSet.clear();

	// numbers are unique in a Set, so we can keep generating
	// new numbers until the size is max
	while (genSet.size() < 6)
	{
		genSet.insert(rand() % 46 + 1);
	}
}

bool Production::checkRange()
{
	if (genSet.size() > 0)
	{
		for (auto number : genSet)
		{
			if (number <= 1 || number >= 46)
				return false;
		}

		return true;
	}

	return false;
}

// since we use a Set of Ints, duplicates cannot be added to the Set,
// so we can just check the size to confirm there are no duplicates
bool Production::checkDuplicates()
{
	return genSet.size() == 6;
}
