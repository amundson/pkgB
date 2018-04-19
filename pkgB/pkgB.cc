#include "pkgB.h"
#include <iostream>

PkgB::PkgB(bool just_used)
  : just_used(just_used)
{}

int
PkgB::doit() const
{
    std::cout << "I ";
    if (just_used) {
        std::cout << "use ";
    } else {
        std::cout << "am ";
    }
    std::cout << "pkgB.\n";
    return 7;
}
