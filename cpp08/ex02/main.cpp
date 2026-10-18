#include "MutantStack.hpp"

#include <vector>
#include <iostream>

int main()
{

	MutantStack<int> iHatedCpp08Ex02;

	iHatedCpp08Ex02.push(3);
	iHatedCpp08Ex02.push(7);

	MutantStack<int>::iterator begin = iHatedCpp08Ex02.begin();
	MutantStack<int>::iterator end = iHatedCpp08Ex02.end();

	MutantStack<int>::const_iterator fugly = iHatedCpp08Ex02.cbegin();

	(void)fugly;

	begin++;
	end -= 2;

	std::cout << *begin << " " << *end << "\n";

	return 0;
}
