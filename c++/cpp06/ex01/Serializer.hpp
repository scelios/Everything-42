#pragma once

#include <stdint.h>

typedef struct s_Data {
	int i;
} Data;

class Serializer {
private:

public:
	Serializer();
	Serializer(const Serializer &);
	virtual ~Serializer();
	Serializer&	operator=(const Serializer &);

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};