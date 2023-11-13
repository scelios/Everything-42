#include "RPN.hpp"

bool checkArgs(char* str){
	int i = -1;
	if (!str || !str[0])
		return false;
	while (str[++i]){
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/'
			&& str[i] != ' ' && (str[i] < '0' || str[i] > '9'))
			return false;
		if (std::isdigit(str[i]) && str[i + 1] && std::isdigit(str[i + 1]))
			return false;		
	}
	return true;
}

int main(int argc, char **argv){
	if (argc == 2){
		if (checkArgs(argv[1]))
			RPN::result(argv[1]);
		else
			std::cout << "Error: invalid argument tokens" << std::endl;
	}
	else 
		std::cout << "Error: invalid argument quantity";
}