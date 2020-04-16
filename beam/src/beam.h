#ifndef MKHSE_BEAM_H
#define MKHSE_BEAM_H

#include <string>
#include <unordered_map>

using namespace std;

typedef std::unordered_map<std::string, std::string> Dictionary;

class Beam
{
public:
    static Beam* getInstance();

    std::string getString(std::string string);
    std::string beamSearch(std::string beam);
private:
    Dictionary basicDictionary;
    static Beam* instance;
};

#endif
