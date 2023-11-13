#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <set>
# include <map>


class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Not found");
		}
};

#endif