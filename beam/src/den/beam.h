#ifndef MKHSE_BEAM_H
#define MKHSE_BEAM_H

#include <string>
#include <unordered_map>
#include <utility>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <regex>
#include <experimental/iterator>

using namespace std;

namespace beam {
    typedef std::map<std::string, std::string> Dictionary;
    typedef std::vector<std::string> Tokens;
    typedef bool Flag;

    class Beam {
    public:
        static Beam *getInstance();
        Beam();
        std::string getString(const std::string &string);
        std::string beamSearch(const std::string &beam);
    private:
        static Beam *instance;
        Tokens mResult;
        std::string mResultString;
        Tokens mNumSeq;
        Tokens mAbbrSeq;
        Flag mNumFlag;
        Flag mAbbrFlag;

        std::string vectorToBeam(const std::vector<std::string> &vector, const std::string &delimiter);

        [[nodiscard]] std::vector<std::string> tokenizeBeam(const std::string &beam) const;

        std::string main(const std::string &beam);

        std::string processNumSeq(const std::vector<std::string> &numSeq);

        void finishNumSeq(const std::string &token);

        void finishAbbrSeq();

        void dealWithNumberToken(const std::string &token);

        void checkSequencesAreNotEmpty();

        void applyRegex();

        std::string mBB(const std::vector<std::string> &vector);

        void afterProc();
    };
}

#endif
