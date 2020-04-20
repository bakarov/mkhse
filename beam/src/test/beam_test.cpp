#define BOOST_TEST_MODULE beam_test

#include "../den/beam.h"
#include <boost/test/included/unit_test.hpp>

namespace bunt = boost::unit_test;

using namespace std;

struct Fixture {
    Fixture() {}

    ~Fixture() {}
};

BOOST_FIXTURE_TEST_CASE(beam_test, Fixture) {
    std::string testLine = "my number is twenty three four five";
    Beam* beam = Beam::getInstance();
    std::string true_result = "my number is 2345";
    std::string pred_result = beam->beamSearch(testLine);

    BOOST_TEST(true_result == pred_result);
}