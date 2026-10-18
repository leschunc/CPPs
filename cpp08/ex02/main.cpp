#include "MutantStack.hpp"

#include <iostream>
#include <list>

void canonTest()
{
	MutantStack<int> iHatedCpp08Ex02;
	iHatedCpp08Ex02.push(3);
	iHatedCpp08Ex02.push(7);

	MutantStack<int> futile(iHatedCpp08Ex02);
	MutantStack<int> abhorrent;
	abhorrent = futile;
}

void iteratorTest()
{
	MutantStack<int> iHatedCpp08Ex02;
	iHatedCpp08Ex02.push(3);
	iHatedCpp08Ex02.push(7);

	MutantStack<int>::iterator begin = iHatedCpp08Ex02.begin();
	MutantStack<int>::iterator end = iHatedCpp08Ex02.end();

	MutantStack<int>::const_iterator fugly = iHatedCpp08Ex02.cbegin();
	MutantStack<int>::const_iterator huh = iHatedCpp08Ex02.cend() - 1;

	begin++;
	end -= 2;

	std::cout << *begin << " " << *end << "\n";
	std::cout << *fugly << "\n";
	std::cout << *huh << "\n";
}

void why()
{
	MutantStack<int> iHatedCpp08Ex02;
	iHatedCpp08Ex02.push(24);

	MutantStack<int>::const_iterator fugly = iHatedCpp08Ex02.cbegin();
	fugly++;

	try
	{
		fugly++;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void subjectTest()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "---------------------\n";
	{
		{
			std::list<int> justAList;
			justAList.push_back(5);
			justAList.push_back(17);
			std::cout << *--justAList.end() << std::endl;
			justAList.pop_back();
			std::cout << justAList.size() << std::endl;
			justAList.push_back(3);
			justAList.push_back(5);
			justAList.push_back(737);
			justAList.push_back(0);
			std::list<int>::iterator it = justAList.begin();
			std::list<int>::iterator ite = justAList.end();
			++it;
			--it;
			while (it != ite)
			{
				std::cout << *it << std::endl;
				++it;
			}
			std::list<int> s(justAList);
		}
	}
}

void batchTest()
{
	canonTest();
	std::cout << "---------------------\n";
	
	iteratorTest();
	std::cout << "---------------------\n";

	why();
	std::cout << "---------------------\n";

	subjectTest();
	std::cout << "---------------------\n";
}

int main()
{

	batchTest();

	return 0;
}
