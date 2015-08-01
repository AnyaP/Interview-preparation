#include <cassert>
#include <iostream>

#define CHECK_EQUAL(answer, etalon) \
    { \
        auto lhs = answer; \
        auto rhs = etalon; \
        if (lhs != rhs) { \
            std::cout << std::boolalpha \
                      << "Check Failed: " << #answer << " != " << #etalon << ". " \
                      << "Expected: " << rhs << ", found: " << lhs << ". " << std::endl; \
        } \
    }
