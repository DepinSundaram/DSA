#include <iostream>

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node (int x, Node* next) : val(x), next(next) {}
};



/* This is a C++ class for a singly linked list with functions to insert, reverse, print elements, and
swap nodes. */
class LL {

public:
    LL() : m_root(nullptr), m_length(1) {}

/**
 * This function inserts a new node with a given value at the end of a linked list.
 * 
 * @param n The value to be inserted as a new node in the linked list.
 */
    void Insert(int n) {
        Node* newLL = new Node(n);
        if (!m_root) {
            m_root = newLL;
        } else {
            Node* temp = m_root;
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newLL;
        }
        m_length++;
    }

/**
 * The Reverse function reverses the order of a linked list.
 */
    void Reverse() {

        Node* prev = nullptr;
        Node* next = nullptr;
        Node* curr = m_root;


        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        m_root = prev;
    }


/**
 * This function prints the values of all elements in a linked list.
 */
    void PrintElements() {
        Node* temp = m_root;

        while(temp) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }


    void Swap(int a, int b) {
        Node* l1 = nullptr;
        Node* l1prev = nullptr;
        Node* l1next = nullptr;

        Node* l2 = nullptr;
        Node* l2prev = nullptr;
        Node* l2next = nullptr;

        Node* temp = m_root;

        for (int i = 0; i < m_length; i++) {
            if (temp->val == a) {
                l1 = temp;
                l1next = temp->next;
                break;
            }
            l1prev = temp;
            temp = temp->next;
        }
        temp = m_root;
        for (int i = 0; i < m_length; i++) {
            if (temp->val == b) {
                l2 = temp;
                l2next = temp->next;
                break;
            }
            l2prev = temp;
            temp = temp->next;
        }
        //printf("l1 = %d\n l1prev = %d\n l1next = %d\n*****\n", l1->val,l1prev->val, l1next->val);
       // printf("l2 = %d\n l2prev = %d\n l2next = %d\n*****\n", l2->val,l2prev->val, l2next->val);
        // check for first element

        if (l1 && l2) {
            if (l1prev == nullptr) {
                m_root = l2;
            } else {
                l1prev->next = l2;
            }
            l2->next = l1next;
            l2prev->next = l1;
            l1->next = l2next;
        }

    }

private :
    Node* m_root;
    int m_length;
};



int main() {

    LL ll;
    ll.Insert(1);
    ll.Insert(2);
    ll.Insert(3);
    ll.Insert(4);
    ll.Insert(5);

    ll.PrintElements();
    ll.Reverse();
    ll.PrintElements();
    ll.Swap(1, 4);
    ll.PrintElements();

}