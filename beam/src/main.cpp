#include <iostream>
#include "beam.h"

int main() {
    Beam* mB = new Beam();
    std::cout << mB->beamSearch("hello how are you") << std::endl;
    return 0;
}
