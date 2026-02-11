#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>

class Serialize
{
private:
	Serialize();
	Serialize(const Serialize &copy);
	Serialize &operator=(const Serialize &copy);
	~Serialize();

public:
	static uintptr_t serialize(Data *ptr);
	Data *deserialize(uintptr_t raw);
};

#endif