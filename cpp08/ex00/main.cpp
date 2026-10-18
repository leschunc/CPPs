#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{

	std::vector<char> v;

	for (size_t i = 0; i < 11; i++)
		v.push_back("hello world"[i]);

	try
	{
		std::cout << *easyfind(v, 'e') << "\n";
		std::cout << *easyfind(v, 'a') << "\n";
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << e.what() << '\n';
	}

	v.insert(v.begin(), 'a');
	easyfind(v, 'a');

	return 0;
}
