#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdint.h>
#include <sys/time.h>
#include <math.h>

Base *generate(void)
{
    std::cout << "__________________________\n\n";
    switch ((rand() % 3))
    {
    case 0:
    {
        std::cout << "Class\tA\n";
        return new A;
    }
    case 1:
    {
        std::cout << "Class\t\tB\n";

        return new B;
    }
    default:
    {
        std::cout << "Class\t\t\tC\n";
        return new C;
    }
    }
}

void identify(Base *p)
{
    A *a = dynamic_cast<A *>(p);
    if (a != NULL)
    {
        std::cout << "PTR\tA\n";
    }

    B *b = dynamic_cast<B *>(p);
    if (b != NULL)
    {
        std::cout << "PTR\t\tB\n";
    }

    C *c = dynamic_cast<C *>(p);
    if (c != NULL)
    {
        std::cout << "PTR\t\t\tC\n";
    }
}

void identify(Base &p)
{
    try
    {
        A a = dynamic_cast<A &>(p);
        std::cout << "REF\tA\n";
    }
    catch (const std::exception &e)
    {
        try
        {
            B b = dynamic_cast<B &>(p);
            std::cout << "REF\t\tB\n";
        }
        catch (const std::exception &e)
        {
            try
            {
                C c = dynamic_cast<C &>(p);
                std::cout << "REF\t\t\tC\n";
            }
            catch (const std::exception &e)
            {
                std::cout << "REF: >>>>>>> it's a nothing??\n";
            }
        }
    }
}

void seed()
{
	struct timeval now;
	gettimeofday(&now, NULL);
	srand(now.tv_usec);
}

int main()
{

    seed();

    for (size_t i = 0; i < 13; i++)
    {
        Base *basePtr = generate();

        identify(basePtr);

        identify(*basePtr);

        delete basePtr;
    }

    return 0;
}
