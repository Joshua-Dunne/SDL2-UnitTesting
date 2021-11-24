#include "../include/Production.h"
#include <iostream>
#include <time.h>

int main()
{
	// generate randomness based on time
	srand (time(NULL));
	
	
	std::cout << "Running Lottery!" << std::endl;
	Production p;
	p.generateLottery();

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
	
	std::cin.get();
	
	return 0;
}
