# include <iostream>
# include <unordered_set>
# include <vector>
# include <random>

std::random_device rd;
std::mt19937 gen(rd());


struct Node {
    Node* next = nullptr;
    int data;

    Node(int d) {
        data = d;
    }
};


class List {
    Node* head = nullptr;

public:
    explicit List(const std::vector<int>& values) {
        if (values.empty()) {
            head = nullptr;
        } else {
            head = new Node(values[0]);
            Node* current = head;
            for (size_t i = 1; i < values.size(); ++i) {
                current->next = new Node(values[i]);
                current = current->next;
            }
        }
    }

    ~List() {
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr) {
            previous = current;
            current = current->next;
            delete previous;
        }
    }

    void DeleteDuplicates() {
        if (head == nullptr) {
            return;
        }
        std::unordered_set<int> occured;
        Node* previous = head;
        Node* current = head->next;
        occured.insert(head->data);
        while (current) {
            if (occured.find(current->data) != occured.end()) {
                previous->next = current->next;
                delete current;
            } else {
                occured.insert(current->data);
                previous = current;
            }
            current = previous->next;
        }
    }

    void Print() const {
        for (Node* current = head; current != nullptr; current = current->next) {
            std::cout << current->data << std::endl;
        }
    }

    Node* GetHead() const {
        return head;
    }

    int GetSize() const {
        int size = 0;
        for (Node* current = head; current != nullptr; current = current->next) {
            ++size;
        }
        return size;
    }
};


void CheckListsAreEqual(const List& firstList, const List& secondList) {
    Node* first = firstList.GetHead();
    Node* second = secondList.GetHead();
    bool areEqual = true;
    while (first != nullptr && second != nullptr)  {
        if (first->data != second->data) {
            areEqual = false;
            break;
        }
        first = first->next;
        second = second->next;
    }
    if (first != nullptr || second != nullptr) {
        areEqual = false;
    }

    if (!areEqual) {
        std::cout << "Check faild.\n" << "Found: ";
        firstList.Print();
        std::cout << "Expected: ";
        secondList.Print();
    }
}

void TestCase(std::vector<int> sample, std::vector<int> correct) {
    List sampleList(sample);
    sampleList.DeleteDuplicates();
    List correctList(correct);

    CheckListsAreEqual(sampleList, correctList);
}


void TestRandom(int listLength, int valuesRange) {
    // random vector
    std::uniform_int_distribution<> dis(0, valuesRange);
    std::vector<int> sample(listLength);
    for (int i = 0; i < sample.size(); ++i) {
        sample[i] = dis(gen);
    }

    List sampleList(sample);
    sampleList.DeleteDuplicates();
    int size = sampleList.GetSize();
    sampleList.DeleteDuplicates();
    if (sampleList.GetSize() != size) {
        std::cout << "Check failed for calling DeleteDuplicates twice.";
    }

}


void TestDeleteDuplicates() {
    // check equal for core cases
    TestCase({}, {});
    TestCase({1}, {1});
    TestCase({1, 1, 1, 1, 1}, {1});
    TestCase({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});
    TestCase({1, 1, 1, 2, 2, 2}, {1, 2});
    TestCase({1, 2, 1, 2, 1, 2}, {1, 2});
    TestCase({1, 2, 2, 8, 8, 8, 5, 2, 3, 1}, {1, 2, 8, 5, 3});

    // delete duplicates twice for random lists
    TestRandom(100, 1000);
    TestRandom(100, 100);
    TestRandom(100, 10);
}

int main() {
    TestDeleteDuplicates();
    return 0;
}

