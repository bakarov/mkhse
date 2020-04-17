#ifndef MKHSE_BEAM_H
#define MKHSE_BEAM_H

#include <string>
#include <unordered_map>
#include <utility>
#include <regex>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <experimental/iterator>

using namespace std;

typedef std::map<std::string, std::string> Dictionary;

class Beam
{
public:
    static Beam* getInstance();

    Beam();
    std::string getString(std::string string);
    std::string beamSearch(std::string beam);
    Dictionary numberDictionary;
    Dictionary measureDictionary;
    Dictionary symbolDictionary;
private:
    static Beam* instance;
    std::string vectorToBeam(std::vector<std::string> vector, std::string delimiter);
    std::vector<std::string> tokenizeBeam(std::string beam);
    std::string main(std::string beam);
    std::string processNumSeq(std::vector<std::string> numSeq);
    std::string mBB(std::vector<std::string> vector);
};

#endif
