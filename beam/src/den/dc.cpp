#include "dc.h"

namespace beam {
    const Dictionary Dc::numberDictionary = {
            {"zero",      "0"},
            {"one",       "1"},
            {"two",       "2"},
            {"three",     "3"},
            {"four",      "4"},
            {"five",      "5"},
            {"six",       "6"},
            {"seven",     "7"},
            {"eight",     "8"},
            {"nine",      "9"},
            {"ten",       "10"},
            {"eleven",    "11"},
            {"twelve",    "12"},
            {"thirteen",  "13"},
            {"fourteen",  "14"},
            {"fifteen",   "15"},
            {"sixteen",   "16"},
            {"seventeen", "17"},
            {"eighteen",  "18"},
            {"nineteen",  "19"},
            {"twenty",    "20"},
            {"thirty",    "30"},
            {"forty",     "40"},
            {"fifty",     "50"},
            {"sixty",     "60"},
            {"seventy",   "70"},
            {"eighty",    "80"},
            {"ninety",    "90"},
            {"hundred",   "100"},
            {"thousand",  "1000"}
    };
    const Dictionary Dc::measureDictionary = {
            {"atmoshphere", "atm"},
            {"centimeter",  "cm"},
            {"dalton",      "Da"},
            {"decibel",     "db"},
            {"hectare",     "ha"},
            {"hertz",       "Hz"},
            {"gallon",      "gl"},
            {"gram",        "g"},
            {"kilogram",    "kg"},
            {"kilometer",   "km"},
            {"meter",       "m"},
            {"mile",        "mi"},
            {"milligram",   "mg"},
            {"milliliter",  "ml"},
            {"millimeter",  "m"},
            {"nanometer",   "nm"},
    };
    const Dictionary Dc::symbolDictionary = {
            {"ampersand",  "&"},
            {"asterisk",   "*"},
            {"backslash",  "\\"},
            {"comma",      ","},
            {"dollar",     "$"},
            {"euro",       "€"},
            {"percent",    "%"},
            {"semicolon",  ";"},
            {"tilde",      "~"},
            {"underscore", "_"},
    };
    const Dictionary Dc::fractionDictionary = {
            {"half",    "2"},
            {"third",   "3"},
            {"fourth",  "4"},
            {"fifth",   "5"},
            {"sixth",   "6"},
            {"seventh", "7"},
            {"eighth",  "8"},
            {"nienth",  "9"}
    };
    const std::set<std::string> Dc::d = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    const std::set<std::string> Dc::dozens = {"10", "20", "30", "40", "50", "60", "70", "80", "90"};
    const std::set<std::string> Dc::dozenDigits = {"10", "20", "30", "40", "50", "60", "70", "80", "90", "11", "12", "13",
                                         "14", "15", "16", "17", "18", "19"};
}
