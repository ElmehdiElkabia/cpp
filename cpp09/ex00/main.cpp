#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc input.txt" << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange btc;

		btc.loadDatabase("data.csv");
		// btc.printDatabase();
		btc.processInput(argv[1]);

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}