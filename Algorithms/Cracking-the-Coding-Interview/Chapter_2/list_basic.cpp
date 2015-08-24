#include <iostream>

class Node {
    Node* next = nullptr;
    int data;

public:
    Node () {}

    explicit Node (int d) {
        data = d;
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

void DeleteList (Node* head) {
    Node* p = head;
    while (p != nullptr) {
        p = p->GetNext();
        delete p;
    }
}


int main() {
    Node* myList = new Node();
    myList->Append(25);
    for (Node* nodePtr = myList; nodePtr != 0; nodePtr = nodePtr->GetNext()) {
        std::cout << nodePtr->GetData() << std::endl;
    }
    DeleteList(myList);
    return 0;
}
