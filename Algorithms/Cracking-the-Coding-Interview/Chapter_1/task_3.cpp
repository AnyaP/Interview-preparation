#include "../../testing.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// 1. assume that characters are ASCII
// 2. create an array for checking (256-length)
// 3. check and copy if the character is new

const int ALPHABET_SIZE = 256;

std::string RemoveDuplicates(std::string s) {
    std::vector<bool> occurred(ALPHABET_SIZE, false);
    int tail = 0;
    for (int i = 0; i < s.size(); ++i) {
        auto c = static_cast<unsigned char>(s[i]);
        if (!occurred[c]) {
            s[tail] = s[i];
            ++tail;
            occurred[c] = true;
        }
    }
    s.resize(tail);
    return s;
}

// time: O(n), space: additional 256-array

void SortAndCompare(std::string raw, std::string correct) {
    std::string result = RemoveDuplicates(raw);
    std::sort(result.begin(), result.end());
    std::sort(correct.begin(), correct.end());
    CHECK_EQUAL(result, correct);
}

void TestRemoveDuplicates() {
    SortAndCompare("", "");
    SortAndCompare("a", "a");
    SortAndCompare("aaa", "a");
    SortAndCompare("abcde", "abcde");
    SortAndCompare("ababab", "ab");
    SortAndCompare("aaabbbb", "ab");
    SortAndCompare("bd2bb22aZkl", "bd2aZkl");
}

int main()
{
    std::string ex = "abcdeff";
    std::cout << RemoveDuplicates(ex) << std::endl;
    TestRemoveDuplicates();
    return 0;
}
