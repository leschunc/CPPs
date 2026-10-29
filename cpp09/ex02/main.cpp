#include "PmergeMe.hpp"

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

int main()
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

	return 0;
}
