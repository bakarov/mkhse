#define BOOST_TEST_MODULE beam_test

#include "../den/beam.h"
#include <boost/test/included/unit_test.hpp>

namespace bunt = boost::unit_test;

using namespace std;
using namespace beam;

struct Fixture
{
    static Fixture*& instance() {
        static Fixture* inst = 0;
        return inst;
    }

    Fixture() {
        instance() = this;
        Beam beam = Beam();
    }

    ~Fixture() {
    }

    Beam beam;
};

BOOST_AUTO_TEST_SUITE(BeamTest)

    BOOST_GLOBAL_FIXTURE(Fixture);

    BOOST_AUTO_TEST_CASE(Test1) {
        const std::string
                input = "the number is one two three four five six seven eight nine",
                true_output = "the number is 123456789";
        const std::string output = Fixture::instance()->beam.beamSearch(input);
        std::cout << output << std::endl;
        BOOST_REQUIRE_EQUAL(output == true_output, true);
    }

    BOOST_AUTO_TEST_CASE(Test2) {
        const std::string
                input = "one hundred and two hundred and three thousand",
                true_output = "100 and 200 and 3000";
        const std::string output = Fixture::instance()->beam.beamSearch(input);
        std::cout << output << std::endl;
        BOOST_REQUIRE_EQUAL(output == true_output, true);
    }

    BOOST_AUTO_TEST_CASE(Test3) {
        const std::string
                input = "twenty two and thirty three and forty four and fifty five",
                true_output = "22 and 33 and 44 and 55";
        const std::string output = Fixture::instance()->beam.beamSearch(input);
        std::cout << output << std::endl;
        BOOST_REQUIRE_EQUAL(output == true_output, true);
    }

    BOOST_AUTO_TEST_CASE(Test4) {
        const std::string
                input = "one fifth and one fourth",
                true_output = "1/5 and 1/4";
        const std::string output = Fixture::instance()->beam.beamSearch(input);
        std::cout << output << std::endl;
        BOOST_REQUIRE_EQUAL(output == true_output, true);
    }


BOOST_AUTO_TEST_SUITE_END()

