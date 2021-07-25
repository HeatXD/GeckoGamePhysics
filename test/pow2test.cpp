#include "../include/ext/doctest/doctest.h"
// Test Example
int pow2(int n)
{
    if (n == 0)
        return 0;

    int ret;

    if (n < 0)
    {
        ret = -1;
        for (int i = 0; i > n; i--)
            ret *= 2;
    }
    else
    {
        ret = 1;
        for (int i = 0; i < n; i++)
            ret *= 2;
    }
    return ret;
}

TEST_CASE("Testing Pow2 Function")
{
    CHECK(pow2(-3) == -8);
    CHECK(pow2(-2) == -4);
    CHECK(pow2(-1) == -2);
    CHECK(pow2(0) == 0);
    CHECK(pow2(1) == 2);
    CHECK(pow2(2) == 4);
    CHECK(pow2(3) == 8);
}