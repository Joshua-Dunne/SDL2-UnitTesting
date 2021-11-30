#include "../include/Production.h"
#include <iostream>
#include <time.h>

int main()
{
	// generate randomness based on time
	srand (time(NULL));

	std::cout << "Running Lottery!" << std::endl;
	Production p;

	while(p.genSet.size() < 6)
	{
		std::cout << "Please enter 6 numbers from 1 to 46 (inclusive): ";
		int num;

		std::cin >> num;

		if(num < 1 || num > 46)
		{
			std::cout << "Number is below 1 / above 46, please try again." << std::endl;
			continue;
		}

		std::set<int>::iterator it = p.genSet.begin();
		bool dup = false;

			while(it != p.genSet.end())
			{
				if(num == *it)
				{
					std::cout << "Number is already in the Lottery, please try again." << std::endl;
					dup = true;
					break;
				}

				it++;
			}

		if(dup)
			continue;


		std::cout << num << " accepted, adding to Lottery." << std::endl;
		p.genSet.insert(num);
	}

	bool rangeCheck = p.checkRange();

	if(rangeCheck)
	{
		std::cout << "Numbers are all in range!" << std::endl;
	}

	bool dupCheck = p.checkDuplicates();

	if(dupCheck)
	{
		std::cout << "No duplicates found!" << std::endl;
	}

	std::cout << "Numbers drawn: ";

	int count = 0;

	for(auto num : p.genSet)
	{
		if(count < 5)
			std::cout << num << ", ";
		else
		std::cout << num << std::endl;

		count++;
	}
	
	system("pause");

	return 0;
}
