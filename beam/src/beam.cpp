#include "beam.h"


Beam* Beam::instance = nullptr;

Beam::Beam() {
    numberDictionary["zero"] = "0";
    numberDictionary["one"] = "1";
    numberDictionary["two"] = "2";
    numberDictionary["three"] = "3";
    numberDictionary["four"] = "4";
    numberDictionary["five"] = "5";
    numberDictionary["six"] = "6";
    numberDictionary["seven"] = "7";
    numberDictionary["eight"] = "8";
    numberDictionary["nine"] = "9";
    numberDictionary["ten"] = "10";
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

std::string Beam::beamSearch(std::string beam_) {
    std::string beam = std::move(beam_);
    std::vector<std::string> beam_tokens = tokenizeBeam(beam);
    std::vector<std::string> result;
    for (auto token : beam_tokens)
    {
        result.push_back(token);
    }
    std::string meam = vectorToBeam(result);
    return meam;
}