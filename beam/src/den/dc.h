#ifndef BEAM_DC_H
#define BEAM_DC_H

#include <string>
#include <set>
#include <map>

namespace beam {
    typedef std::map<std::string, std::string> Dictionary;

    struct Dc {
        static const Dictionary numberDictionary;
        static const Dictionary measureDictionary;
        static const Dictionary symbolDictionary;
        static const Dictionary fractionDictionary;
        static const std::set<std::string> d;
        static const std::set<std::string> dozens;
        static const std::set<std::string> dozenDigits;
    };
}

#endif //BEAM_DC_H
