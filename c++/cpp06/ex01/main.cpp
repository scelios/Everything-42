#include "Serializer.hpp"
#include <iostream>

int main() {
	Data d;
	d.i = 42;
	std::cout << "before " << &d << ' ' << d.i << std::endl;
	uintptr_t raw = Serializer::serialize(&d);
	Data *ptr = Serializer::deserialize(raw);
	std::cout << "after  " << ptr << ' ' << ptr->i << std::endl;
	return 0;
}