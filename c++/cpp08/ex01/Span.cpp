#include "Span.hpp"

Span::Span() : _size(2){}

Span::Span(unsigned int n) : _size(n){}

Span::Span(const Span &copy){*this = copy;}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		_vector = copy._vector;
		_size = copy._size;
	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(int n)
{
	if (_vector.size() < _size)
		_vector.push_back(n);
	else
		throw std::logic_error("Vector is full");
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vector.size() + std::distance(begin, end) <= _size)
		_vector.insert(_vector.end(), begin, end);
	else
		throw std::logic_error("Vector is full");
}

int Span::shortestSpan()
{
	if (_vector.size() < 2)
		throw std::logic_error("Not enough elements");
	std::sort(_vector.begin(), _vector.end());
	std::vector<int>::iterator it = _vector.begin();
	std::vector<int>::iterator ite = _vector.end() - 1;
	int min = std::abs(*ite - *(it));
	while (it != ite)
	{
		if (std::abs(*it - *(it + 1)) < min)
			min = std::abs(*it - *(it + 1));
		it++;
	}
	return min;
}

int Span::longestSpan()
{
	if (_vector.size() < 2)
		throw std::logic_error("Not enough elements");
	std::sort(_vector.begin(), _vector.end());
	std::vector<int>::iterator it = _vector.begin();
	std::vector<int>::iterator ite = _vector.end() - 1;
	int max = std::abs(*ite - *(it));
	return max;
}



