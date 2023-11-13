#include "RPN.hpp"


RPN::RPN(){}

RPN::RPN(const RPN &ref){*this = ref;}

RPN& RPN::operator=(const RPN &ref){(void)ref;return *this;}

RPN::~RPN(){}

void RPN::result(char *str) {
	std::string expression(str);
	std::stack<double> stack;

	std::istringstream iss(expression);
	std::string word;

	while (iss >> word) 
	{
		const char *str = word.c_str();
		if (isdigit(word[0]))
		{
			stack.push(std::strtod(str, NULL));
			if (stack.top() > 9)
			{
				std::cerr << "Error: Invalid char." << std::endl;
				return ;
			}
		}
		
		else if (word.size() == 1 && (word[0] == '+' || word[0] == '-' || word[0] == '*' || word[0] == '/')) 
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error: Insufficient operands for operation." << std::endl;
				return ;
			}

			double second = stack.top();
			stack.pop();
			double first = stack.top();
			stack.pop();

			switch (word[0]) 
			{
				case '+':
					stack.push(first + second);
					break;
				case '-':
					stack.push(first - second);
					break;
				case '*':
					stack.push(first * second);
					break;
				case '/':
					if (second == 0) 
					{
						std::cerr << "Error: Division by zero." << std::endl;
						return ;
					}
					stack.push(first / second);
					break;
				default:
					std::cerr << "Error: Invalid operator." << std::endl;
					return ;
			}
		} 
		else 
		{
			std::cerr << "Error: Invalid char." << std::endl;
			return ;
		}
	}

	if (stack.size() != 1) 
	{
		std::cerr << "Error: Invalid expression." << std::endl;
		return ;
	}

	std::cout << stack.top() << std::endl;
}