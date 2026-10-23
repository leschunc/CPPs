#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	BitcoinExchange btx;
	try
	{
		btx.openFileCheck(ac, av);
		// cout << "File opened succesfully\n\n";
		btx.loadFileCheck();

		// btx.dbShowMap();

		btx.readInput();

	}
	catch (const std::exception &e)
	{
		cerr << e.what() << "\n";
	}

	return 0;
}
