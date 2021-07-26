#include <cstdint>
#include <iostream>

typedef struct	s_data
{
	int a;
}				Data;

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data test = {0};
	Data *ptr = &test;

	std::cout << "init a : " << ptr->a << std::endl;
	std::cout << "increment init a : " << ++ptr->a << std::endl;

	uintptr_t raw = serialize(ptr);
	std::cout << "serialized : " << raw << std::endl;

	Data *des = deserialize(raw);

	std::cout << "after deserialization pointers are " << ((des == ptr) ? "equal\n" : "not equal\n");
	std::cout << "a of deserialized ptr : " << des->a << std::endl;

	return (0);
}