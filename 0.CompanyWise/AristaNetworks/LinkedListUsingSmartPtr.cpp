#include <iostream>
#include <memory>


struct LLNode {
    int value;
    std::unique_ptr<LLNode> next;
    LLNode(int value) : value(value), next(nullptr) {}
};


class LL {
    std::unique_ptr<LLNode> head = nullptr;
public:
    void insert (int value) {
        std::unique_ptr<LLNode> node = std::make_unique<LLNode>(value);
        if (head == nullptr) {
            head = std::move(node);
            return;
        } else {
            LLNode* cur = head.get();
            while (cur->next != nullptr) {
                cur = cur->next.get();
            }
            cur->next = std::move(node);
        }
    }

    void remove(int val) {
        if (head->value == val) {
            head = std::move(head->next);
            return;
        }

        LLNode* cur = head.get();

        while (cur->next !=nullptr && cur->next->value != val) {
            cur = cur->next.get();
        }

        if(cur->next !=nullptr) {
            cur->next = std::move(cur->next->next);
        }
    }

    void print() {
        LLNode* current = head.get();
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next.get();
        }
        std::cout << std::endl;
    }
};

int main() {

    LL list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print(); // Output: 1 2 3
    list.remove(2);
    list.print(); // Output: 1 3
    return 0;
}