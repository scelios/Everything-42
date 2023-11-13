#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <cstdlib>

class Span
{
private:
	std::vector<int> _vector;
	unsigned int _size;
	Span();
public:
	Span(unsigned int n);
	Span(const Span &copy);
	~Span();
	Span &operator=(const Span &copy);
	void addNumber(int n);
	void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();
};

#endif