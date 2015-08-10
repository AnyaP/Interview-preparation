#include <iostream>

class Node {
    Node* next;
    int data;

public:
    Node () {
        next = 0;
    }

    Node (int d) {
        data = d;
        next = 0;
    }

    void Append (int d) {
        Node* newNode = new Node(d);
        Node* tail = this;
        while (tail->next != 0) {
            tail = tail->next;
        }
        tail->next = newNode;
    }

    Node* GetNext() {
        return this->next;
    }

    int GetData() {
        return this->data;
    }
};


int main() {
    Node* myList = new Node(5);
    myList->Append(25);
    for (Node* nodePtr = myList; nodePtr != 0; nodePtr = nodePtr->GetNext()) {
        std::cout << nodePtr->GetData() << std::endl;
    }
    return 0;
}
