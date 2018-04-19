#include "pkgA.h"
#include <iostream>

PkgA::PkgA(bool just_used)
  : just_used(just_used)
{}

int
PkgA::doit() const
{
    std::cout << "I ";
    if (just_used) {
        std::cout << "use ";
    } else {
        std::cout << "am ";
    }
    std::cout << "pkgA.\n";
    return 7;
}
