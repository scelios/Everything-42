#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base {
public:
	virtual ~Base();

};

class A : public Base {};

class B : public Base {};

class C : public Base {};

#endif