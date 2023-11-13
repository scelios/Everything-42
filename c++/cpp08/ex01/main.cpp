#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	std::cout << "Shortest span with only one element: ";
	try {sp.shortestSpan();}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}

	std::cout << "Longest span with only one element: ";
	try {sp.longestSpan();}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}

	sp.addNumber(0);
	sp.addNumber(5);
	sp.addNumber(2000);
	sp.addNumber(17);
	sp.addNumber(18);

	std::cout << "Add element when span is full: ";
	try {sp.addNumber(11);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	std::cout << "Shortest span = "<< sp.shortestSpan() << std::endl;
	std::cout << "Longest span = "<< sp.longestSpan() << std::endl;

	std::cout << "New Span of 10003" << std::endl;
	Span sp2 = Span(10003);
	sp2.addNumber(5);
	std::vector<int> v(10000, 0);
	sp2.addRange(v.begin(), v.end());
	sp2.addNumber(3);
	sp2.addNumber(9);
	
	std::cout << "Shortest span = "<< sp2.shortestSpan() << std::endl;
	std::cout << "Longest span = "<< sp2.longestSpan() << std::endl;
	
	return 0;
}