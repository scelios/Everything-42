#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <sstream>



class RPN
{
private:
	RPN();
public:
	RPN(const RPN &ref);
	RPN& operator=(const RPN &ref);
	~RPN();
	static void result(char *str);
};

#endif