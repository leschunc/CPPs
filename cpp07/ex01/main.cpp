#include "iter.hpp"
#include <iostream>

void	constCharRef(const char &c)
{
	std::cout << c;
}

void	nonConstCharRef(char &c)
{
	std::cout << c;
}

int main(void)
{
	
	const std::string constStr = "this is const\n";

	iter(constStr, constStr.size(), constCharRef);

	std::string nonConstStr = "this is not const\n";
	
	iter(nonConstStr, nonConstStr.size(), nonConstCharRef);

	return 0;
}
