#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &src) {(void) src;}
Serializer::~Serializer() {}

Serializer&	Serializer::operator=(const Serializer &src) {
	//if (this == &src) return (*this);
	(void) src;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t> (ptr);
	// return ptr->i;
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*> (raw);
	// Data *ptr = new Data;
	// ptr->i = raw;
	// return ptr;
}