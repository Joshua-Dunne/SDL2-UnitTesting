#include "../include/Production.h"

void Production::generateLottery()
{
	// clear any data that may exist before generation
	if (genSet.size() > 0)
		genSet.clear();

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

bool Production::checkDuplicates()
{
	return genSet.size() == 6;
}
