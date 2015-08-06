#include "../../testing.h"

#include <string>
#include <iostream>

// 1. assume that characters are ASCII
// 2. create an array for checking (256-length)
// 3. check and copy if the character is new

std::string RemoveDuplicates(std::string s) {
    bool occured[256];
    for (int i = 0; i < 256; ++i) {
        occured[i] = false;
    }
    auto tail = s.begin();
    for (auto it = s.begin(); it < s.end(); ++it) {
        // the character is new
        if (!occured[static_cast<unsigned char>(*it)]) {
            *tail = *it;
            ++tail;
            occured[static_cast<unsigned char>(*it)] = true;
        }
        // else - just ignore
    }
    s.resize(tail - s.begin());
    return s;
}

// time: O(n), space: additional 256-array

void TestRemoveDuplicates() {
    CHECK_EQUAL(RemoveDuplicates(""), "");
    CHECK_EQUAL(RemoveDuplicates("a"), "a");
    CHECK_EQUAL(RemoveDuplicates("aaa"), "a");
    CHECK_EQUAL(RemoveDuplicates("abcde"), "abcde");
    CHECK_EQUAL(RemoveDuplicates("ababab"), "ab");
    CHECK_EQUAL(RemoveDuplicates("aaabbbb"), "ab");
    CHECK_EQUAL(RemoveDuplicates("bd2bb22aZkl"), "bd2aZkl");
}

int main()
{
    std::string ex = "abcdeff";
    std::cout << RemoveDuplicates(ex) << std::endl;
    TestRemoveDuplicates();
    return 0;
}
