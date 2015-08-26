#include <vector>
#include <list>
#include <forward_list>
#include <assert.h>
#include <iostream>

const int BUFF_SIZE = 100;

struct Node {
    int value;
    int index;
};

class ThreeStacks {
    std::vector<Node> buffer;
    std::vector<int> topIndices = {-1, -1, -1};
    std::forward_list<int> freeCells;

    public:
    // Probably I could initialize in a more beautiful way? :)
    ThreeStacks() {
        buffer.resize(BUFF_SIZE);
        for (size_t i = 0; i < BUFF_SIZE; ++i) {
            freeCells.push_front(i);
        }
    }

    void push(int value, int stackNumber) {
        if (freeCells.empty()) {
            throw std::length_error("Buffer is full");
        }
        int index = freeCells.front();
        buffer[index].value = value;
        buffer[index].index = topIndices[stackNumber];
        topIndices[stackNumber] = index;
        freeCells.pop_front();
    }

    bool empty(int stackNumber) {
        return topIndices[stackNumber] < 0;
    }

    int top(int stackNumber) {
        assert(!empty(stackNumber));
        return buffer[topIndices[stackNumber]].value;
    }

    void pop(int stackNumber) {
        assert(!empty(stackNumber));
        int index = topIndices[stackNumber];
        topIndices[stackNumber] = buffer[index].index;
        freeCells.push_front(index);
    }
};


int main() {
    // no tests.. should I create some?
    ThreeStacks stacks;
    stacks.push(33, 2);
    std::cout << stacks.top(2) << std::endl;
    stacks.pop(2);
    return 0;
}
