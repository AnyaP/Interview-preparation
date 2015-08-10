# include "../../testing.h"
# include <iostream>
# include <vector>

struct Node {
    Node* next;
    int data;

    Node(int d) {
        data = d;
        next = 0;
    }
};

// assume that both numbers contain at least one digit
Node* SumListsAsNumbers(Node* first, Node* second) {
    bool memory = 0;
    if (first->data + second->data > 9) {
        memory = 1;
    }
    Node* result = new Node((first->data + second->data) % 10);

    Node* inResult = result;
    Node* inFirst = first->next;
    Node* inSecond = second->next;
    while (inFirst or inSecond or memory) {
        int value = memory;
        if (inFirst != 0) {
            value += inFirst->data;
            inFirst = inFirst->next;
        }
        if (inSecond != 0) {
            value += inSecond->data;
            inSecond = inSecond->next;
        }
        if (value > 9) {
            memory = 1;
        } else {
            memory = 0;
        }
        inResult->next = new Node(value % 10);
        inResult = inResult->next;
    }
    return result;
}

Node* CreateList(std::vector<int> values) {
    if (values.size() == 0) {
        return 0;
    }
    Node* head = new Node(values[0]);
    Node* current = head;
    for (int i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}

void PrintList(Node* head) {
    for (Node* current = head; current; current = current->next) {
        std::cout << current->data << std::endl;
    }
}

int ListToNumber(Node* head) {
    int number = 0;
    int pos = 1;
    for (Node* current = head; current; current = current->next) {
        number += current->data * pos;
        pos *= 10;
    }
    return number;
}

void TestSumListsAsNumbers() {
    Node* first = CreateList({1, 1, 1});
    Node* second = CreateList({5, 5, 5});
    CHECK_EQUAL(ListToNumber(SumListsAsNumbers(first, second)), 666);

    first = CreateList({3, 1, 1});
    second = CreateList({5, 1, 9});
    CHECK_EQUAL(ListToNumber(SumListsAsNumbers(first, second)), 1028);

    first = CreateList({8, 5});
    second = CreateList({7});
    CHECK_EQUAL(ListToNumber(SumListsAsNumbers(first, second)), 65);

    first = CreateList({9});
    second = CreateList({1});
    CHECK_EQUAL(ListToNumber(SumListsAsNumbers(first, second)), 10);

}

int main() {
    TestSumListsAsNumbers();
    return 0;
}

