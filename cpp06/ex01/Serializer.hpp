#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data
{
    std::string hello;
    std::string bye;
};

class Serializer
{
private:
    // OCF
    Serializer();
    Serializer(const Serializer &ref);
    ~Serializer();
    const Serializer &operator=(const Serializer &);

public:
    // methods
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif