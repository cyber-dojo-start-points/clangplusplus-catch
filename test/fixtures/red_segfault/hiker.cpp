#include "hiker.hpp"

int answer()
{
    // Reading through a null pointer. The pointer is volatile so the read
    // really happens under -O, and the process dies on the spot. Catch
    // installs a signal handler, counts the test case as a failure and
    // prints its summary, so this reaches red rather than amber.
    volatile int* p = nullptr;
    return *p;
}
