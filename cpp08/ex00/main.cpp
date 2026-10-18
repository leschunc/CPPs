#include "easyfind.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

int main()
{

	std::vector<int> v;

	for (size_t i = 0; i < 11; i++)
		v.push_back("hello world"[i]);
	
	try
	{
		easyfind(v, 'e');
		easyfind(v, 'a');
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << e.what() << '\n';
	}

	v.insert(v.begin(), 'a');
	easyfind(v, 'a');

	return 0;

}
