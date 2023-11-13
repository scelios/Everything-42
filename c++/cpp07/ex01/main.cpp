#include "iter.hpp"

template<typename T>
void	iter(T *array, int len, void (*f)(T const &))
{
	for(int i = 0; i < len; i++)
		f(array[i]);
}

template<typename T>
void	print(const T &data)
{
	std::cout << data << std::endl;
}

template <class T>
void	swap(T &a, T &b)
{
	T	aux = a;
	a = b;
	b = aux;
}

template <typename T>
T const	&max(T const &a, T const &b)
{
	return( a > b ? a : b);
}

template <typename T>
T const &min(T const &a, T const &b)
{
	return( a < b ? a : b);
}

template <class T>
void bubbleSort(T *a, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; i < j; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}

int	main()
{
	int	intArray[5] = {42, 41, 40, 39, 38};
	std::string	stringArray[5] = {"42", "zpalfi", "cpp07", "hola", "adios"};
	float	floatArray[3] = {42.42, 69.69, 42.69};

	std::cout << "Result of iter the int array:" << std::endl;
	::bubbleSort<int>(intArray, 5);
	::iter<int>(intArray, 5, ::print);

	std::cout << std::endl << std::endl << "Result of iter the string array" << std::endl;
	::bubbleSort<std::string>(stringArray, 5);
	::iter<std::string>(stringArray, 5, ::print);

	std::cout<< std::endl << std::endl << "Result of iter the float array" << std::endl;
	::bubbleSort<float>(floatArray, 3);
	::iter<float>(floatArray, 3, ::print);
	std::cout << std::endl;
}

/*class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}*/
