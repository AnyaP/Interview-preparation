# include "../../testing.h"
# include <iostream>
# include <vector>
# include <cmath>

struct Node {
    Node* next;
    int data;

    Node(int d): data (d), next(nullptr) {}
};


Node* SumListsAsNumbers(Node* first, Node* second) {
    bool headIsCreated = false;
    Node *result = nullptr, *head = nullptr;
    int value = 0;
    while (first or second or value) {
        if (first != nullptr) {
            value += first->data;
            first = first->next;
        }
        if (second != nullptr) {
            value += second->data;
            second = second->next;
        }

        if (!headIsCreated) {
            result = new Node(value % 10);
            head = result;
            headIsCreated = true;
        } else {
            result->next = new Node(value % 10);
            result = result->next;
        }

        value /= 10;
    }
    return head;
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
    const int radix = 10;
    int radixPower = 0;
    int number = 0;
    for (Node* current = head; current; current = current->next) {
        number += current->data * pow(radix, radixPower);
        ++radixPower;
    }
    return number;
}


void TestSumListsAsNumbers() {
    CHECK_EQUAL(
        ListToNumber(SumListsAsNumbers(
            CreateList({}),
            CreateList({}))),
        0);
    CHECK_EQUAL(
        ListToNumber(SumListsAsNumbers(
            CreateList({0}),
            CreateList({}))),
        0);
    CHECK_EQUAL(
        ListToNumber(SumListsAsNumbers(
            CreateList({}),
            CreateList({1}))),
        1);
    CHECK_EQUAL(
        ListToNumber(SumListsAsNumbers(
            CreateList({1, 1, 1}),
            CreateList({5, 5, 5}))),
        666);
    CHECK_EQUAL(
        ListToNumber(SumListsAsNumbers(
            CreateList({3, 1, 1}),
            CreateList({5, 1, 9}))),
        1028);
    CHECK_EQUAL(
        ListToNumber(SumListsAsNumbers(
            CreateList({2, 1, 1, 1, 1, 1, 1, 1}),
            CreateList({7}))),
        11111119);
    CHECK_EQUAL(
        ListToNumber(SumListsAsNumbers(
            CreateList({9, 9, 9}),
            CreateList({1}))),
        1000);
}

int main() {
    TestSumListsAsNumbers();
    return 0;
}

