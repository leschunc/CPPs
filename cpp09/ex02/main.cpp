#include "PmergeMe.hpp"
#include <unistd.h>
#include <climits>

size_t size = 8;
size_t jump;
std::vector<int> elements;

void dispVec()
{
	// std::cout << "jump " << jump << "\n";
	for (size_t i = 0; i < size; i++)
		std::cout << elements[i] << " ";
	std::cout << "\n\n";
}

void loop()
{
	srand(time(0));
	elements.reserve(size);
	for (size_t i = 0; i < size; i++)
		elements.push_back(rand() % (size * 10));

	for (jump = 2; jump <= size; jump *= 2)
	{
		dispVec();

		for (size_t i = 0; (i * jump + jump) <= size; i++)
		{
			size_t one = i * jump;
			size_t two = i * jump + jump / 2;
			if (*(elements.begin() + one) < *(elements.begin() + two))
				std::swap_ranges(elements.begin() + one, elements.begin() + two, elements.begin() + two);
		}
	}
	dispVec();
	jump /= 2;
	for (; jump >= 2; jump /= 2)
	{
		std::cout << jump << "\n";
		// dispVec();
	}
}

void bits(size_t num)
{
	char c;
	for (size_t i = sizeof(num) * 8 - 1; i != -1UL; i--)
	{
		c = ((num >> i) & 1) + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

size_t jacobIndex(size_t bound)
{
	if (bound > INT_MAX)
		return -1;
	size_t jacob = 0;

	for (size_t i = 0; i < bound; i++)
	{
		if (i % 2 == 0)
			jacob = jacob << 1;
		else
			jacob = (jacob << 1) + 1;
	}
	if (bound % 2)
		jacob++;

	return jacob;
}

size_t jacobUpper(size_t nmemb)
{
	if (nmemb == 0)
		return 1;
	if (nmemb > INT_MAX)
		return -1;
	size_t jacob = 0;
	for (size_t i = 0; jacob <= nmemb; i++)
		jacob = jacobIndex(i);
	return jacob;
}

size_t jacobNext(size_t num)
{

	if (num > INT_MAX)
		return -1;
	size_t lower = jacobUpper(num >> 1);

	num--;

	if (num == lower || lower != -1UL)
		return jacobUpper(num + 1);
	else
		return num;
}

int main()
{

	// loop();

	// size_t jacob = 0;

	// for (size_t i = 0; i < 32; i++)
	// {
	// 	std::cout << jacob << "\n";
	// 	jacob = jacobNext(jacob);
	// }

	
	for (size_t i = 0; i < 10; i++)
	{
	std::cout << jacobNext(i) << "\n";
	}
	


	return 0;
}
