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
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = newNode;
    }

    Node* GetNext() const {
        return this->next;
    }

    int GetData() const {
        return this->data;
    }
};

void DeleteList (Node* head) {
    Node* current = head;
    Node* previous;
    while (current != nullptr) {
        Node* previous = current;
        current = current->GetNext();
        delete previous;
    }
}


int main() {
    Node* myList = new Node();
    myList->Append(25);
    for (Node* nodePtr = myList; nodePtr != nullptr; nodePtr = nodePtr->GetNext()) {
        std::cout << nodePtr->GetData() << std::endl;
    }
    DeleteList(myList);
    return 0;
}
