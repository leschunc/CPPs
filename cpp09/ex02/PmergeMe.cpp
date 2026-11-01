#include "PmergeMe.hpp"

#include <cerrno>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

int PmergeMe::parseToken(const std::string &token)
{
	if (token.empty() || token.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error("invalid number: " + token);
	errno = 0;
	long value = std::strtol(token.c_str(), NULL, 10);
	if (errno == ERANGE || value > INT_MAX)
		throw std::runtime_error("number too large: " + token);
	if (value == 0)
		throw std::runtime_error("number is not positive: " + token);
	return static_cast<int>(value);
}

/* ************************************************************************** */
/*                                 std::vector                                */
/* ************************************************************************** */

void PmergeMe::loadVector(int argc, char **argv)
{
	_vec.clear();
	for (int i = 1; i < argc; i++)
	{
		std::istringstream iss(argv[i]);
		std::string token;
		while (iss >> token)
			_vec.push_back(parseToken(token));
	}
	if (_vec.empty())
		throw std::runtime_error("no input");
}

/*
 * Returns the indices of `keys` in sorted order (Knuth, TAOCP Vol.3, 5.3.1).
 * Working on indices keeps each element's identity, so duplicates stay paired
 * with their partner through the recursion.
 */
std::vector<size_t> PmergeMe::fordJohnsonVector(const std::vector<int> &keys)
{
	const size_t n = keys.size();
	if (n < 2)
		return std::vector<size_t>(n, 0);

	const size_t m = n / 2;
	std::vector<size_t> winners;
	std::vector<size_t> losers;
	std::vector<int> winnerKeys;
	winners.reserve(m);
	losers.reserve(m);
	winnerKeys.reserve(m);
	for (size_t i = 0; i + 1 < n; i += 2)
	{
		size_t big = i;
		size_t small = i + 1;
		if (keys[big] < keys[small])
			std::swap(big, small);
		winners.push_back(big);
		losers.push_back(small);
		winnerKeys.push_back(keys[big]);
	}

	std::vector<size_t> order = fordJohnsonVector(winnerKeys);

	// a[j], b[j] are 1-based as in Knuth: a1 <= a2 <= ... and b[j] < a[j].
	std::vector<size_t> a(m + 1);
	std::vector<size_t> b(m + 2);
	for (size_t j = 1; j <= m; j++)
	{
		a[j] = winners[order[j - 1]];
		b[j] = losers[order[j - 1]];
	}
	const bool hasStraggler = (n % 2 == 1);
	const size_t pendCount = m + (hasStraggler ? 1 : 0);
	if (hasStraggler)
		b[m + 1] = n - 1;

	std::vector<size_t> chain;
	chain.reserve(n);
	chain.push_back(b[1]);
	std::vector<size_t> posOfA(m + 1);
	for (size_t j = 1; j <= m; j++)
	{
		posOfA[j] = chain.size();
		chain.push_back(a[j]);
	}

	size_t prevJacob = 1;
	size_t jacob = 1;
	while (prevJacob < pendCount)
	{
		size_t nextJacob = jacob + 2 * prevJacob;
		prevJacob = jacob;
		jacob = nextJacob;

		size_t groupEnd = jacob < pendCount ? jacob : pendCount;
		for (size_t j = groupEnd; j > prevJacob; j--)
		{
			size_t hi = (j <= m) ? posOfA[j] : chain.size();
			size_t lo = 0;
			const int value = keys[b[j]];
			while (lo < hi)
			{
				size_t mid = lo + (hi - lo) / 2;
				if (value < keys[chain[mid]])
					hi = mid;
				else
					lo = mid + 1;
			}
			chain.insert(chain.begin() + lo, b[j]);
			for (size_t k = 1; k <= m; k++)
				if (posOfA[k] >= lo)
					posOfA[k]++;
		}
	}
	return chain;
}

void PmergeMe::sortVector()
{
	std::vector<size_t> order = fordJohnsonVector(_vec);
	std::vector<int> sorted;
	sorted.reserve(_vec.size());
	for (size_t i = 0; i < order.size(); i++)
		sorted.push_back(_vec[order[i]]);
	_vec.swap(sorted);
}

/* ************************************************************************** */
/*                                 std::deque                                 */
/* ************************************************************************** */

void PmergeMe::loadDeque(int argc, char **argv)
{
	_deq.clear();
	for (int i = 1; i < argc; i++)
	{
		std::istringstream iss(argv[i]);
		std::string token;
		while (iss >> token)
			_deq.push_back(parseToken(token));
	}
	if (_deq.empty())
		throw std::runtime_error("no input");
}

std::deque<size_t> PmergeMe::fordJohnsonDeque(const std::deque<int> &keys)
{
	const size_t n = keys.size();
	if (n < 2)
		return std::deque<size_t>(n, 0);

	const size_t m = n / 2;
	std::deque<size_t> winners;
	std::deque<size_t> losers;
	std::deque<int> winnerKeys;
	for (size_t i = 0; i + 1 < n; i += 2)
	{
		size_t big = i;
		size_t small = i + 1;
		if (keys[big] < keys[small])
			std::swap(big, small);
		winners.push_back(big);
		losers.push_back(small);
		winnerKeys.push_back(keys[big]);
	}

	std::deque<size_t> order = fordJohnsonDeque(winnerKeys);

	std::deque<size_t> a(m + 1);
	std::deque<size_t> b(m + 2);
	for (size_t j = 1; j <= m; j++)
	{
		a[j] = winners[order[j - 1]];
		b[j] = losers[order[j - 1]];
	}
	const bool hasStraggler = (n % 2 == 1);
	const size_t pendCount = m + (hasStraggler ? 1 : 0);
	if (hasStraggler)
		b[m + 1] = n - 1;

	std::deque<size_t> chain;
	chain.push_back(b[1]);
	std::deque<size_t> posOfA(m + 1);
	for (size_t j = 1; j <= m; j++)
	{
		posOfA[j] = chain.size();
		chain.push_back(a[j]);
	}

	size_t prevJacob = 1;
	size_t jacob = 1;
	while (prevJacob < pendCount)
	{
		size_t nextJacob = jacob + 2 * prevJacob;
		prevJacob = jacob;
		jacob = nextJacob;

		size_t groupEnd = jacob < pendCount ? jacob : pendCount;
		for (size_t j = groupEnd; j > prevJacob; j--)
		{
			size_t hi = (j <= m) ? posOfA[j] : chain.size();
			size_t lo = 0;
			const int value = keys[b[j]];
			while (lo < hi)
			{
				size_t mid = lo + (hi - lo) / 2;
				if (value < keys[chain[mid]])
					hi = mid;
				else
					lo = mid + 1;
			}
			chain.insert(chain.begin() + lo, b[j]);
			for (size_t k = 1; k <= m; k++)
				if (posOfA[k] >= lo)
					posOfA[k]++;
		}
	}
	return chain;
}

void PmergeMe::sortDeque()
{
	std::deque<size_t> order = fordJohnsonDeque(_deq);
	std::deque<int> sorted;
	for (size_t i = 0; i < order.size(); i++)
		sorted.push_back(_deq[order[i]]);
	_deq.swap(sorted);
}

/* ************************************************************************** */

static double elapsedUs(std::clock_t start, std::clock_t end)
{
	return static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

void PmergeMe::run(int argc, char **argv)
{
	// Parse once up front so invalid input fails before anything is printed.
	loadVector(argc, argv);

	std::cout << "Before:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	std::clock_t start = std::clock();
	loadVector(argc, argv);
	sortVector();
	double vecTime = elapsedUs(start, std::clock());

	start = std::clock();
	loadDeque(argc, argv);
	sortDeque();
	double deqTime = elapsedUs(start, std::clock());

	std::cout << "After:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
			  << " elements with std::deque  : " << deqTime << " us" << std::endl;
}
