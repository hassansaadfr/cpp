#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int	main(void)
{
	Data initial(42);

	uintptr_t serialized = serialize(&initial);
	Data *deserialized(deserialize(serialized));

	std::cout << "value of initial " << initial.get_value() << " value of deserialized object " << deserialized->get_value() << std::endl;
	return 0;
}
