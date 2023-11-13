#include "BitcoinExchange.hpp"

int main(int a, char **b)
{
	if (a != 2)
	{
		std::cout << "Usage: ./btc [file]" << std::endl;
		return 1;
	}
	try
	{
		Bitcoin bitcoin("data.csv");
		bitcoin.add_file(b[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;	
}