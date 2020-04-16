#include <iostream>
#include "beam.h"

int main() {
    Beam* mB = new Beam();
    std::cout << mB->getString("Hello, World") << std::endl;
    return 0;
}
