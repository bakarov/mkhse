#ifndef MKHSE_BEAM_H
#define MKHSE_BEAM_H

#include <string>
#include <unordered_map>
#include <utility>
#include <regex>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef std::unordered_map<std::string, std::string> Dictionary;

class Beam
{
public:
    static Beam* getInstance();

    Beam();
    std::string getString(std::string string);
    std::string beamSearch(std::string beam);
    Dictionary numberDictionary;
private:
    static Beam* instance;
    std::string vectorToBeam(std::vector<std::string> vector);
    std::vector<std::string> tokenizeBeam(std::string beam);
};

#endif
