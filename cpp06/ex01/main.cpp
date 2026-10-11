#include "Serializer.hpp"

int main()
{
    Data a;

    a.hello = "hola soy dora";

    uintptr_t uIP = Serializer::serialize(&a);

    Data *dPtr = Serializer::deserialize(uIP);

    std::cout << dPtr->hello << "\n";

    std::cout << "&a: " << &a << "\nData *: " << dPtr << "\n";

    return 0;
}
