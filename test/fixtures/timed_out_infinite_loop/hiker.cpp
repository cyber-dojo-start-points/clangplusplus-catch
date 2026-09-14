#include "hiker.hpp"

int answer()
{
    // The learner meant to count up to 42 and never moves n. The counter is
    // volatile so the loop is still there under -O, where a loop that does
    // nothing to a plain local can be optimised away and the kata finish.
    volatile int n = 0;
    while (n != 42)
    {
    }
    return n;
}
