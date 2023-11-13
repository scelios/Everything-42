#ifndef	ITER_HPP
# define ITER_HPP

# include <iostream>


template<typename T>
void	iter(T *array, int len, void (*f)(T const &));

template<typename T>
void	print(const T &data);

template <class T>
void	swap(T &a, T &b);

template <typename T>
T const	&max(T const &a, T const &b);

template <typename T>
T const &min(T const &a, T const &b);

template <class T>
void bubbleSort(T *a, int n);

#endif