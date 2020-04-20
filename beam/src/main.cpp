#include <iostream>
#include "beam.h"

int main() {
    Beam* mB = new Beam();
    std::cout << mB->beamSearch("what a b c twenty two for four and twenty with three hundred fifty five") << std::endl;
    return 0;
}
