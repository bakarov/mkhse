#include "beam.h"

#include <utility>

Beam* Beam::instance = nullptr;

Beam* Beam::getInstance()
{
    if (instance == 0)
    {
        instance = new Beam();
    }
    return instance;
}

std::string Beam::getString(std::string string) {
    return string;
}

std::string Beam::beamSearch(std::string beam) {
    std::string string = std::move(beam);
    return string;
}