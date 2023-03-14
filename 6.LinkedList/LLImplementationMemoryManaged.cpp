#include <iostream>

class LinkedListNode {
public:
    int value;
    LinkedListNode* next;

    LinkedListNode(int value) : value(value), next(nullptr) {}
    ~LinkedListNode() {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        while (head != nullptr) {
            LinkedListNode* current = head;
            head = head->next;
            delete current;
        }
    }

    void insert(int value) {
        LinkedListNode* node = new LinkedListNode(value);
        if (head == nullptr) {
            head = node;
        } else {
            LinkedListNode* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }
    }

    void remove(int value) {
        if (head == nullptr) {
            return;
        }
        if (head->value == value) {
            LinkedListNode* current = head;
            head = head->next;
            delete current;
            return;
        }
        LinkedListNode* current = head;
        while (current->next != nullptr && current->next->value != value) {
            current = current->next;
        }
        if (current->next != nullptr) {
            LinkedListNode* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            delete nodeToDelete;
        }
    }

    void print() {
        LinkedListNode* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    LinkedListNode* head;
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print(); // Output: 1 2 3
    list.remove(2);
    list.print(); // Output: 1 3
    return 0;
}
