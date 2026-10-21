#include "BitcoinExchange.hpp"

using std::cerr;
using std::cout;

int main(int ac, char *av[])
{
	BitcoinExchange btx;
	try
	{
		btx.openFileCheck(ac, av);
		cout << "File opened succesfully\n";
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << "\n";
	}

	return 0;
}
