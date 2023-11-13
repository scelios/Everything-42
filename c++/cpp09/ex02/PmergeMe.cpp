#include "PmergeMe.hpp"



PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(PmergeMe const &other){*this = other;}
PmergeMe &PmergeMe::operator=(PmergeMe const &other){
	*this = other;
	return *this;
}

PmergeMe::PmergeMe(int argc,char **argv){
	fillVector(argc,argv);
	fillList(v1);
	std::cout << "Before: ";
	printVector(v1);
	// std::cout << "List:" << std::endl;
	// printList(v2);
	time_t start = clock();
	mergeSort(v1);
	time_t end = clock();
	std::cout << "After: ";
	printVector(v1);
	time_t start2 = clock();
	// std::cout << "List:" << std::endl;
	mergeSort(v2);
	time_t end2 = clock();
	std::cout << "Time to process a range of " << v1.size() << " elements with std::vector : " << (double)(end - start) << " us" << std::endl;
	std::cout << "Time to process a range of " << v1.size() << " elements with std::list : " << (double)(end2 - start2) << " us" << std::endl;

	// printList(v2);
}

void PmergeMe::fillVector(int argc,char **argv){
	for (int i = 1; i < argc; i++)
		v1.push_back(atoi(argv[i]));
}

void PmergeMe::fillList(std::vector <int> &v){
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		v2.push_back(*it);
}

void PmergeMe::printVector(std::vector <int> &v){
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::printList(std::list <int> &v){
	for (std::list<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::mergeSort(std::vector <int> &v){
	if (v.size() <= 1)
		return;
	std::vector<int> left;
	std::vector<int> right;
	int middle = ((int)v.size() + 1) / 2;
	for (int i = 0; i < middle; i++)
		left.push_back(v[i]);
	for (int i = middle; i < (int)v.size(); i++)
		right.push_back(v[i]);
	mergeSort(left);
	mergeSort(right);
	v.clear();
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(v));
}

void PmergeMe::mergeSort(std::list <int> &v){
	if (v.size() <= 1)
		return;
	std::list<int> left;
	std::list<int> right;
	int middle = ((int)v.size() + 1) / 2;
	int i = 0;
	for (std::list<int>::iterator it = v.begin(); it != v.end(); ++it){
		if (i < middle)
			left.push_back(*it);
		else
			right.push_back(*it);
		i++;
	}
	mergeSort(left);
	mergeSort(right);
	v.clear();
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(v));
}

