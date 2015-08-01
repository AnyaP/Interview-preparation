#include "../../../testing.h"

#include <string>

bool AllUnique(const std::string& s)
{
    // Your code goes here.
}

void TestAll()
{
    // Positive examples
    CHECK_EQUAL(AllUnique("x"), true);
    CHECK_EQUAL(AllUnique("abc"), true);

    // Negative examples
    CHECK_EQUAL(AllUnique("aba"), false);
    CHECK_EQUAL(AllUnique("cc"), false);

    // Corner cases
    CHECK_EQUAL(AllUnique(""), true);
}

int main()
{
    TestAll();
    return 0;
}
