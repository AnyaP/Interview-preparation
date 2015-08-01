#include "../../testing.h"

#include <string>
#include <iostream>

bool AllUnique(const std::string& s)
{
    // Your code goes here.
    return true;
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
    std::cout << "hello" << std::endl;
    TestAll();

    return 0;
}
