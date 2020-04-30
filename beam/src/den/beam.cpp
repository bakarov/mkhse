#include "beam.h"
#include "dc.h"

namespace beam {
    Beam *Beam::instance = nullptr;

    Beam::Beam() = default;

    Beam *Beam::getInstance() {
        if (instance == 0) {
            instance = new Beam();
        }
        return instance;
    }


    std::string Beam::getString(const std::string &string) {
        return string;
    }

    std::string Beam::vectorToBeam(const std::vector<std::string> &vector, const std::string &delimiter) {
        std::ostringstream result_string;
        if (!vector.empty()) {
            std::copy(vector.begin(), vector.end() - 1,
                      std::experimental::make_ostream_joiner(result_string, delimiter));
            result_string << vector.back();
        }
        return result_string.str();
    }

    std::string Beam::mBB(const std::vector<std::string> &vector) {
        std::ostringstream result_string;
        if (!vector.empty()) {
            std::copy(vector.begin(), vector.end() - 1,
                      std::ostream_iterator<std::string>(result_string, " "));
            result_string << vector.back();
        }
        return result_string.str();
    }

    std::vector<std::string> Beam::tokenizeBeam(const std::string &beam) const {
        regex beam_splitter("\\s+");
        sregex_token_iterator iterator(beam.begin(), beam.end(), beam_splitter, -1);
        sregex_token_iterator end;
        vector<std::string> beam_tokens(iterator, end);
        return beam_tokens;
    }

    std::string Beam::processNumSeq(const std::vector<std::string> &numSeq) {
        std::vector<std::string> processedSeq;
        int size = numSeq.size();
        for (auto i = 0; i != size; ++i) {
            if (numSeq[i] == "1000") {
                if (i == size - 1) {
                    processedSeq.emplace_back("000");
                } else if (Dc::dozenDigits.find(numSeq[i + 1]) != Dc::dozenDigits.end()) {
                    processedSeq.emplace_back("0");
                } else if (Dc::d.find(numSeq[i + 1]) != Dc::d.end()) {
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
                } else if (Dc::dozenDigits.find(numSeq[i + 1]) != Dc::dozenDigits.end()) {
                    processedSeq.emplace_back("");
                } else if (Dc::d.find(numSeq[i + 1]) != Dc::d.end()) {
                    processedSeq.emplace_back("0");
                }
            } else if (Dc::dozens.find(numSeq[i]) != Dc::dozens.end() && i != size - 1) {
                if (Dc::d.find(numSeq[i + 1]) != Dc::d.end()) {
                    std::string s;
                    s.push_back(numSeq[i][0]);
                    processedSeq.emplace_back(s);
                } else {
                    processedSeq.emplace_back(numSeq[i]);
                }
            } else {
                processedSeq.emplace_back(numSeq[i]);
            }
        }
        return vectorToBeam(processedSeq, "");
    }

    void Beam::finishNumSeq(const std::string &token) {
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

    void Beam::dealWithNumberToken(const std::string &token) {
        if (!mNumFlag) {
            mNumFlag = true;
        }
        mNumSeq.push_back(Dc::numberDictionary.at(token));
        if (mAbbrFlag) {
            finishAbbrSeq();
        }
    }

    std::string Beam::main(const std::string &beam) {
        Tokens beam_tokens = tokenizeBeam(beam);
        for (auto i = 0; i != beam_tokens.size(); ++i) {
            std::string token = beam_tokens[i];
            if (Dc::numberDictionary.find(token) != Dc::numberDictionary.end()) {
                dealWithNumberToken(token);
            } else {
                if (mNumFlag) {
                    finishNumSeq(token);
                } else if (Dc::measureDictionary.find(token) != Dc::measureDictionary.end()) {
                    mResult.push_back(Dc::measureDictionary.at(token));
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
        Beam::afterProc();
        mResultString = mBB(mResult);
        // applyRegex();
        return mResultString;
    }

    void Beam::applyRegex() {
        // mResultString = regex_replace(mResultString, regex(" (%)", "$1"));
    }

    void Beam::afterProc() {
        Tokens processedTokens;
        for (auto i = 0; i != mResult.size(); ++i) {
            if (i != mResult.size() - 1) {
                if (Dc::d.find(mResult[i]) != Dc::d.end() &&
                        Dc::fractionDictionary.find(mResult[i + 1]) != Dc::fractionDictionary.end()) {
                    processedTokens.emplace_back(mResult[i] + '/' + Dc::fractionDictionary.at(mResult[i + 1]));
                    ++i;
                } else {
                    processedTokens.emplace_back(mResult[i]);
                }
            } else {
                processedTokens.emplace_back(mResult[i]);
            }
        }
        mResult = processedTokens;
    }

    std::string Beam::beamSearch(const std::string &beam) {
        mResult.clear();
        mNumSeq.clear();
        mAbbrSeq.clear();
        mNumFlag = false;
        mAbbrFlag = false;
        std::string meam = main(beam);
        return meam;
    }
}