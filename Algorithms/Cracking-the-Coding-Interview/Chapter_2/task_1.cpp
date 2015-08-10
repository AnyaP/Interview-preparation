# include <iostream>
# include <unordered_map>
# include <vector>

struct Node {
    Node* next;
    int data;

    Node(int d) {
        data = d;
        next = 0;
    }
};

void DeleteDuplicates(Node* head) {
    std::unordered_map<int, bool> table;
    Node* previous = head;
    Node* current = head->next;
    table[head->data] = true;
    while (current) {
        if (table.find(current->data) != table.end()) {
            previous->next = current->next;
            delete current;
        } else {
            table[current->data] = true;
            previous = current;
        }
        current = previous->next;
    }
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

int main() {
    std::vector<int> a = {1, 2, 2, 8, 8, 8, 5, 2, 3, 1};
    Node* myList = CreateList(a);
    DeleteDuplicates(myList);
    PrintList(myList);

    return 0;
}

