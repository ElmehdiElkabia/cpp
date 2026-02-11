#include "Serializer.hpp"

Serialize::Serialize() {};

Serialize::Serialize(const Serialize &copy) { (void)copy; };

Serialize &Serialize::operator=(const Serialize &copy)
{
	(void)copy;
	return *this;
}

Serialize::~Serialize() {};

uintptr_t Serialize::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serialize::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}