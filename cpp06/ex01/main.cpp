#include "Serializer.hpp"

int main(void) {
	Data original;
	original.id = 42;
	original.name = "Isabella";

	std::cout << GREEN << "ORIGINAL DATA\n" <<
	"ID: " << original.id << "\nName: " << original.name <<
	"\nAddress: " << &original << RESET << std::endl;

	uintptr_t raw = Serializer::serialize(&original);
	std::cout << RED << "Serialized Data (uintptr_t): " << raw << RESET << std::endl;

	Data* restored = Serializer::deserialize(raw);
	std::cout << GREEN << "DESERIALIZED DATA\n" <<
	"ID: " << restored->id << "\nName: " << restored->name <<
	"\nAddress: " << restored << RESET << std::endl;

	return 0;
}