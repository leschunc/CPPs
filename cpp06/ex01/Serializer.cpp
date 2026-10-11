#include "Serializer.hpp"

// OCF
Serializer::Serializer() {}
Serializer::Serializer(const Serializer &ref) { (void)ref; }
Serializer::~Serializer() {}
const Serializer &Serializer::operator=(const Serializer &ref)
{
    if (this == &ref)
        return *this;
    return *this;
}

// methods
uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}
