#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data *originalData = new Data( "Elmehdi",10);

	std::cout << "--- Original Object ---" << std::endl;
	std::cout << "Pointer address: " << originalData << std::endl;
	std::cout << "Data content:    " << originalData->getInt() << ", " << originalData->getString() << std::endl;
	std::cout << std::endl;

	uintptr_t raw = Serialize::serialize(originalData);

	std::cout << "--- Serialized Object ---" << std::endl;
	std::cout << "Raw :   " << raw << std::endl;
	std::cout << std::endl;

	Data *deserializedData = Serialize::deserialize(raw);

	std::cout << "--- Deserialized Object ---" << std::endl;
	std::cout << "Pointer address: " << deserializedData << std::endl;
	std::cout << "Data content:    " << deserializedData->getInt() << ", " << deserializedData->getString() << std::endl;
	std::cout << std::endl;

	std::cout << "--- Verification ---" << std::endl;
	if (originalData == deserializedData)
	{
		std::cout << "SUCCESS" << std::endl;
	}
	else
	{
		std::cout << "FAILURE" << std::endl;
	}

	delete originalData;

	return 0;
}