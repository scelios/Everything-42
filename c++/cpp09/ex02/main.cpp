#include "PmergeMe.hpp"

bool checkArgs(char **argv, int argc){
	int i = 0;
	while (++i < argc)
	{
		char *str = argv[i];
		if (!str || !*str)
			return false;
		while (*str){
			if (!isdigit(*str))
				return false;
			str++;
		}
	}
	return true;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Usage: ./PmergeMe [vector]" << std::endl;
	}
	if (checkArgs(argv, argc) == false)
	{
		std::cout << "Error: invalid vector" << std::endl;
		return 1;
	}
	PmergeMe pm(argc,argv);
	

	return 0;
}