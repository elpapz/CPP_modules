#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <iostream>

int main()
{
    Base *base;
    base = generate();

    std::cout << "POINTER CLASS IDENTITY\n"; 
    identify(base);

    std::cout << std::endl << "REFERENCE CLASS IDENTITY\n"; 
    Base& reference_base = *base;
    identify(reference_base);

    delete(base);
}
