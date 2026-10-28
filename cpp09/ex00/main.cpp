#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{

	BitcoinExchange btx;
	try
	{
		btx.openFileCheck(ac, av);
		btx.readFile();
		btx.readInput();
	}

	catch (const std::exception &e)
	{
		cerr << e.what() << "\n";
	}

	return 0;
}
