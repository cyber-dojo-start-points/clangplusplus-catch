#include "hiker.hpp"
#include <stdexcept>

int answer()
{
    // Nothing catches this. Catch does, and counts the test case that threw
    // as a failure like any other, so this reaches red rather than amber.
    throw std::runtime_error("not worked out yet");
}
