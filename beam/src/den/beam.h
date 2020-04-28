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
typedef std::vector<std::string> Tokens;
typedef bool Flag;

class Beam
{
public:
    static Beam* getInstance();

    Beam();
    std::string getString(const std::string& string);
    std::string beamSearch(const std::string& beam);
    Dictionary numberDictionary;
    Dictionary measureDictionary;
    Dictionary symbolDictionary;
    Dictionary fractionDictionary;
    std::set<std::string> d;
private:
    static Beam* instance;
    Tokens mResult;
    Tokens mNumSeq;
    Tokens mAbbrSeq;
    Flag mNumFlag;
    Flag mAbbrFlag;
    std::string vectorToBeam(const std::vector<std::string>& vector, const std::string& delimiter);
    std::vector<std::string> tokenizeBeam(const std::string& beam) const;
    std::string main(const std::string& beam);
    std::string processNumSeq(const std::vector<std::string>& numSeq);
    void finishNumSeq(const std::string& token);
    void finishAbbrSeq();
    void dealWithNumberToken(const std::string& token);
    void checkSequencesAreNotEmpty();
    std::string mBB(const std::vector<std::string>& vector);
    void afterProc();
};

#endif
