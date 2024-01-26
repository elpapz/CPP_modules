#include "Serializer.hpp"


int main()
{
    Data data;
    data.name = "JESUUUUUS";
    data.age = 180;

    std::cout << "Name: " << data.name << std::endl;
    std::cout << "Age: " << data.age << std::endl;
    std::cout << "Pointers address: " << &data << std::endl;
    std::cout << "Pointer value: " << (unsigned long) &data << std::endl;

    uintptr_t PointerValue = Serializer::serialize(&data);

    std::cout << "\nSerialized value: " << PointerValue << std::endl;

    Data *copy_data = Serializer::deserialize(PointerValue);

    std::cout << "\n[deserialize]Name: " << copy_data->name << std::endl;
    std::cout << "[deserialize]Age: " << copy_data->age << std::endl;
    std::cout << "[deserialize]Pointer address: " << copy_data << std::endl;
    std::cout << "[deserialize]Pointer value: " << (unsigned long) copy_data << std::endl;
}
