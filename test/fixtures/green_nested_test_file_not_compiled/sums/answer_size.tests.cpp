// A test file in a sub-directory. The makefile gathers files with a shallow
// glob, so this one is never compiled and never linked, and the tests in it
// never run. The assertion here is one that would fail, so the green and the
// count of one test case in expected.json together say this file really did
// not run rather than that it ran and passed.

#include "hiker.hpp"
#include <catch2/catch_test_macros.hpp>
#include <string>

TEST_CASE("the answer is three digits long")
{
    REQUIRE( std::to_string(answer()).length() == 3 );
}
