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
            {"thousand", "1000"}
    };
    measureDictionary = {
            {"atmoshphere", "atm"},
            {"centimeter", "cm"},
            {"dalton", "Da"},
            {"decibel", "db"},
            {"hectare", "ha"},
            {"hertz", "Hz"},
            {"gallon", "gl"},
            {"gram", "g"},
            {"kilogram", "kg"},
            {"kilometer", "km"},
            {"meter", "m"},
            {"mile", "mi"},
            {"milligram", "mg"},
            {"milliliter", "ml"},
            {"millimeter", "m"},
            {"nanometer", "nm"},
    };
    symbolDictionary = {
            {"ampersand", "&"},
            {"asterisk", "*"},
            {"backslash", "\\"},
            {"comma", ","},
            {"dollar", "$"},
            {"euro", "€"},
            {"percent", "%"},
            {"semicolon", ";"},
            {"tilde", "~"},
            {"underscore", "_"},
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


std::string Beam::getString(const std::string& string) {
    return string;
}

std::string Beam::vectorToBeam(const std::vector<std::string>& vector, const std::string& delimiter) {
    std::ostringstream result_string;
    if (!vector.empty())
    {
        std::copy(vector.begin(), vector.end() - 1,
                  std::experimental::make_ostream_joiner(result_string, delimiter));
        result_string << vector.back();
    }
    return result_string.str();
}

std::string Beam::mBB(const std::vector<std::string>& vector) {
    std::ostringstream result_string;
    if (!vector.empty()) {
        std::copy(vector.begin(), vector.end()-1,
                  std::ostream_iterator<std::string>(result_string, " "));
        result_string << vector.back();
    }
    return result_string.str();
}

std::vector<std::string> Beam::tokenizeBeam(const std::string& beam) const {
    regex beam_splitter("\\s+");
    sregex_token_iterator iterator(beam.begin(), beam.end(), beam_splitter, -1);
    sregex_token_iterator end;
    vector<std::string> beam_tokens (iterator, end);
    return beam_tokens;
}

std::string Beam::processNumSeq(const std::vector<std::string>& numSeq) {
    std::vector<std::string> processedSeq;
    std::set<std::string> dozens = {"10", "20", "30", "40", "50", "60", "70", "80", "90"};
    std::set<std::string> digits = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    std::set<std::string> dozenDigits = {"10", "20", "30", "40", "50", "60", "70", "80", "90", "11", "12", "13", "14", "15", "16", "17", "18", "19"};
    int size = numSeq.size();
    for (auto i = 0; i != size; ++i) {
        if (numSeq[i] == "1000") {
            if (i == size - 1) {
                processedSeq.emplace_back("000");
            } else if (dozenDigits.find(numSeq[i + 1]) != dozenDigits.end()) {
                processedSeq.emplace_back("0");
            } else if (digits.find(numSeq[i + 1]) != digits.end()) {
                if (i != size - 2) {
                    if (numSeq[i + 2] == "100") {
                        processedSeq.emplace_back("");
                    }
                } else {
                    processedSeq.emplace_back("00");
                }
            }
        } else if (numSeq[i] == "100") {
            if (i == size - 1) {
                processedSeq.emplace_back("00");
            } else if (dozenDigits.find(numSeq[i + 1]) != dozenDigits.end()) {
                processedSeq.emplace_back("");
            } else if (digits.find(numSeq[i + 1]) != digits.end()) {
                processedSeq.emplace_back("0");
            }
        } else if (dozens.find(numSeq[i]) != dozens.end() && i != size - 1) {
            if (digits.find(numSeq[i + 1]) != digits.end()) {
                std::string s;
                s.push_back(numSeq[i][0]);
                processedSeq.emplace_back(s);
            }  else {
                processedSeq.emplace_back(numSeq[i]);
            }
        } else {
            processedSeq.emplace_back(numSeq[i]);
        }
    }
    return vectorToBeam(processedSeq, "");
}

void Beam::finishNumSeq(const std::string& token) {
    mNumFlag = false;
    mResult.push_back(processNumSeq(mNumSeq));
    mNumSeq.clear();
    if (token != "") {
        mResult.push_back(token);
    }
}

void Beam::checkSequencesAreNotEmpty() {
    if (!mNumSeq.empty()) {
        finishNumSeq("");
    }
    if (!mAbbrSeq.empty()) {
        finishAbbrSeq();
    }
}

void Beam::finishAbbrSeq() {
    mAbbrFlag = false;
    std::string abbrString = vectorToBeam(mAbbrSeq, "");
    for (auto &c: abbrString) c = toupper(c);
    mResult.push_back(abbrString);
    mAbbrSeq.clear();
}

void Beam::dealWithNumberToken(const std::string& token) {
    if (!mNumFlag) {
        mNumFlag = true;
    }
    mNumSeq.push_back(numberDictionary[token]);
    if (mAbbrFlag) {
        finishAbbrSeq();
    }
}

std::string Beam::main(const std::string& beam) {
    Tokens beam_tokens = tokenizeBeam(beam);
    for (auto i = 0; i != beam_tokens.size(); ++i) {
        std::string token = beam_tokens[i];
        if (numberDictionary.find(token) != numberDictionary.end()) {
            dealWithNumberToken(token);
        } else {
            if (mNumFlag) {
                finishNumSeq(token);
            } else if (measureDictionary.find(token) != measureDictionary.end()) {
                mResult.push_back(measureDictionary[token]);
            } else {
                if (!mAbbrFlag) {
                    if (token.size() == 1 and beam_tokens[i + 1].size() == 1) {
                        mAbbrFlag = true;
                        mAbbrSeq.push_back(token);
                    } else {
                        mResult.push_back(token);
                    }
                } else {
                    finishAbbrSeq();
                    mResult.push_back(token);
                }
            }
        }
    }
    checkSequencesAreNotEmpty();
    std::string meam = mBB(mResult);
    return meam;
}

std::string Beam::beamSearch(const std::string& beam) {
    mResult.clear();
    mNumSeq.clear();
    mAbbrSeq.clear();
    mNumFlag = false;
    mAbbrFlag = false;
    std::string meam = main(beam);
    return meam;
}