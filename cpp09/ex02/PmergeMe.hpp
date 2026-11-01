#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <string>
#include <vector>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void run(int argc, char **argv);

private:
	std::vector<int> _vec;
	std::deque<int> _deq;

	static int parseToken(const std::string &token);

	void loadVector(int argc, char **argv);
	void sortVector();
	static std::vector<size_t> fordJohnsonVector(const std::vector<int> &keys);

	void loadDeque(int argc, char **argv);
	void sortDeque();
	static std::deque<size_t> fordJohnsonDeque(const std::deque<int> &keys);
};

#endif
