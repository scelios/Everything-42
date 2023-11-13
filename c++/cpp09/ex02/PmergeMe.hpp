#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>


class PmergeMe
{
private:
	std::vector<int> v1;
	std::list<int> v2;
	PmergeMe();
public:
	PmergeMe(int argc,char **argv);
	~PmergeMe();
	PmergeMe(PmergeMe const &other);
	PmergeMe &operator=(PmergeMe const &other);
	void fillVector(int argc,char **argv);
	void fillList(std::vector <int> &v);
	void printVector(std::vector <int> &v);
	void printList(std::list <int> &v);
	void mergeSort(std::vector <int> &v);
	void mergeSort(std::list <int> &v);
};

#endif