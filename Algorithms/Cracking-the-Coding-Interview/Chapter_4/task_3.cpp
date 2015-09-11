# include <iostream>
# include <vector>
# include <algorithm>
#include <cmath>
# include "../../testing.h"

struct Node {
    int value;
    Node* left;
    Node* right;
};

using Iterator = std::vector<int>::const_iterator;

// Creates a balanced binary search tree
// [from; to)
Node* CreateTree(Iterator from, Iterator to) {
    if (to - from == 0) {
        return nullptr;
    }
    Iterator middle = from + (to - from) / 2; // Should I be afraid of (from < to)?
    Node* root = new Node();
    root->value = *middle;
    root->left = CreateTree(from, middle);
    root->right = CreateTree(middle + 1, to);
    return root;
}

void InOrderTraversal(Node* root, std::vector<int>& buff) {
    if (root != nullptr) {
        InOrderTraversal(root->left, buff);
        buff.push_back(root->value);
        InOrderTraversal(root->right, buff);
    }
}

int MaxDepth(Node* tree) {
    if (tree == nullptr) {
        return 0;
    }
    return 1 + std::max(MaxDepth(tree->left), MaxDepth(tree->right));
}

int MinDepth(Node* tree) {
    if (tree == nullptr) {
        return 0;
    }
    return 1 + std::min(MinDepth(tree->left), MinDepth(tree->right));
}

bool CheckBalanced(Node* tree) {
    return MaxDepth(tree) - MinDepth(tree) <= 1;
}

void TestCreateTree(const std::vector<int>& testVector) {
    Node* tree = CreateTree(testVector.begin(), testVector.end());
    std::vector<int> traversedVector;
    InOrderTraversal(tree, traversedVector);
    CHECK_EQUAL(traversedVector, testVector);
    // CHECK_EQUAL(CheckBalanced(tree), true);
    int minimalHeight = testVector.size() == 0?
                        0 : floor(std::log2(testVector.size())) + 1;
    CHECK_EQUAL(MaxDepth(tree), minimalHeight);
}

int main() {
    for (int len = 0; len <= 32; ++len) {
        std::vector<int> v(len);
        std::iota(v.begin(), v.end(), 0); // Does any more frequent way exist to have a range from A to B with step C?
        TestCreateTree(v);
    }
    return 0;
}

