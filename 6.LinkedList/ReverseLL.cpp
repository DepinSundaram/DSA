#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode (int x, ListNode* next) : val(x), next(next) {}
};


class LL {

public :
/*

Time Complexity:

Since we are iterating only once through the list and achieving reversed list. 
Thus, the time complexity is O(N) where N is the number of nodes present in the list.

Space Complexity:

To perform given tasks, no external spaces are used except three-pointers.
So, space complexity is O(1).
*/
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev_p = nullptr;
        ListNode* current_p = head;
        ListNode* next_p = nullptr;

        while (current_p) {
            next_p = current_p->next;
            current_p->next = prev_p;
            prev_p = current_p;
            current_p = next_p;
        }

        head = prev_p;

        return head;
    }

    ListNode* reverseLL2(ListNode* head) {
        ListNode* newhead = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = newhead;
            newhead = head;
            head = next;
        }

        return newhead;
    }


    ListNode* reverseLLRecursive(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* nnode = reverseLLRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return nnode;
    }


/*
Time Complexity :

We are still traversing both lists entirely in the worst-case scenario. 
So, it remains the same as O(N+M) where N is the number of nodes in list 1 and M is the number of nodes in list 2.

Space Complexity :

We are using the same lists just changing links to create our desired list.
 So no extra space is used. Hence, its space complexity is O(1). 


*/
    ListNode* mergeTwoListInplace(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val > l2->val) {
            std::swap(l1, l2);
        }

        ListNode* res = l1;

        while (l1 !=NULL && l2 != NULL) {
            ListNode* temp = NULL;
            while (l1 !=NULL && l1->val <= l2->val) {
                temp = l1;
                l1 = l1->next;
            }
            // link previous sorted node with 
            // next larger node in list2
            temp->next = l2;
            std::swap(l1, l2);
        }
        return res;
    }
/*
Time Complexity: O(N)

Space Complexity: O(1)
*/
    ListNode* RemoveNthNodeFromBack(ListNode* head, int n) {
        ListNode *fast(nullptr), *slow(nullptr);
        fast = slow = head;
        ListNode* start;
        start->next = head;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }


        while (fast->next != nullptr) {
            fast = fast->next;
            slow = fast->next;
        }

        slow->next = slow->next->next;

        return start->next;
    }


    ListNode* addTwoNumber(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;

        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum/10;

            ListNode* node = new ListNode (sum % 10);
            temp->next = node;
            temp = temp->next;
        }

        return dummy->next;
    }

    int lengthOfLinkedList(ListNode* head) {
        int length = 0;
        while(head != NULL) {
            ++length;
            head = head->next;
        }
        return length;
    }
    ListNode* ReverseKNodes(ListNode* head, int k) {
        int len = lengthOfLinkedList(head);

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head, *nex = dummy, *prev = dummy;

        while (len >= k) {
            curr = prev->next;
            nex = curr->next;
            for (int i = 0; i < k; i++) {
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = curr->next;
            }
            prev = curr;
            len -=k;
        }

        return dummy->next;
    }
};


int main () {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(3);



}