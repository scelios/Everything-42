#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

int main(void)
{
	std::vector<int> v1;
	v1.push_back(42);
	v1.push_back(2);
	v1.push_back(34);
	v1.push_back(72);
	
	std::vector<int>::iterator iter = easyfind(v1, 42);
	std::cout << *iter << std::endl;;

	try
	{
		iter = easyfind(v1, -1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}