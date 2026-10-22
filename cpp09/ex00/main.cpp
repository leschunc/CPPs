#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	BitcoinExchange btx;
	try
	{
		btx.openFileCheck(ac, av);
		// cout << "File opened succesfully\n\n";
		btx.loadFileCheck();
		// btx.checkValues();
		btx.dbShowMap();
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << "\n";
	}

	return 0;
}
