#include "PmergeMe.hpp"
#include <unistd.h>

size_t size = 7;
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

size_t jacobIndex(int index)
{
	size_t num = 0;

	if (index > 64)
		return -1;

	if (index == 0)
		return num;
	for (int i = 0; i < index; i++)
	{
		if (i % 2 == 0)
			num = (num << 1) + 1;
		else
			num = num << 1;
	}
	num |= 1;
	return num;
}

size_t upperBound(size_t num)
{
	if (num == -1UL)
		return -1;

	size_t jacob = 0;
	for (size_t i = 0; num > jacob; i++)
		jacob = jacobIndex(i);

	return jacob;
}

size_t lowerBound(size_t num)
{
	if (num == -1UL)
		return -1;

	size_t jacob = -1;
	for (size_t i = 64; num < jacob; i--)
		jacob = jacobIndex(i);

	return jacob;
}

size_t nextJacob(size_t index)
{
	size_t lower = lowerBound(index);
	size_t upper = upperBound(index);

	if (index == 0) return 0;
	if (index == 1) return 1;

	if (lower == upper)
		lower = lowerBound(index - 1);
	
	return lower + upper - index + 1;
}

int main()
{

	loop();

	for (size_t i = 0; i < 50; i++)
	{
		size_t res = nextJacob(i);
		// bits(res);
		std::cout << res << " ";
	}
	std::cout << "\n";

	return 0;
}
