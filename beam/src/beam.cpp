#include "beam.h"


Beam* Beam::instance = nullptr;

Beam::Beam() {
    numberDictionary = {
            {"zero", "0"},
            {"one", "1"},
            {"two", "2"},
            {"three", "3"},
            {"four", "4"},
            {"five", "5"},
            {"six", "6"},
            {"seven", "7"},
            {"eight", "8"},
            {"nine", "9"},
            {"ten", "10"},
            {"eleven", "11"},
            {"twelve", "12"},
            {"thirteen", "13"},
            {"fourteen", "14"},
            {"fifteen", "15"},
            {"sixteen", "16"},
            {"seventeen", "17"},
            {"eighteen", "18"},
            {"nineteen", "19"},
            {"twenty", "20"},
            {"thirty", "30"},
            {"forty", "40"},
            {"fifty", "50"},
            {"sixty", "60"},
            {"seventy", "70"},
            {"eighty", "80"},
            {"ninety", "90"},
            {"hundred", "100"},
    };
}

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

std::string Beam::vectorToBeam(std::vector<std::string> vector) {
    std::ostringstream result_string;
    if (!vector.empty())
    {
        std::copy(vector.begin(), vector.end()-1,
                  std::ostream_iterator<std::string>(result_string, ", "));
        result_string << vector.back();
    }
    return result_string.str();
}

std::vector<std::string> Beam::tokenizeBeam(std::string beam) {
    regex beam_splitter("\\s+");
    sregex_token_iterator iterator(beam.begin(), beam.end(), beam_splitter, -1);
    sregex_token_iterator end;
    vector<std::string> beam_tokens (iterator, end);
    return beam_tokens;
}

std::string Beam::processNumSeq(std::vector<std::string> numSeq) {
    return nullptr;
}

std::string Beam::main(std::string beam) {
    std::vector<std::string> beam_tokens = tokenizeBeam(beam);
    std::vector<std::string> result;
    bool numFlag = false;
    std::vector<std::string> numSeq;
    for (auto i = 0; i != beam_tokens.size(); ++i) {
        std::string token = beam_tokens[i];
        if (numberDictionary.find(beam_tokens[i]) != numberDictionary.end()) {
            if (numFlag == false) {
                numFlag = true;
            }
            numSeq.push_back(numberDictionary[token]);
        } else {
            if (numFlag == true) {
                numFlag = false;
                std::string processedNumSeq = processNumSeq(numSeq);
                result.push_back(processedNumSeq);
                numSeq.clear();
            }
            result.push_back(token);
        }
    }
    std::string meam = vectorToBeam(result);
    return meam;
}

std::string Beam::beamSearch(std::string beam_) {
    std::string beam = std::move(beam_);
    std::string meam = main(beam);
    return meam;
}