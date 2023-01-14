#include <iostream>
/*
Time complexity: O(N) where n is the number of nodes.

Space complexity: O(N), auxiliary space.
*/

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val) {
        left = right = NULL;
    }
};


Node* LCA(Node* node, Node* p, Node* q) {
    // Base
    if (node == NULL || node == p || node == q) {
        return node;
    }

    Node* lN = LCA(node->left, p, q);
    Node* rN = LCA(node->right, p, q);

    if (lN == NULL) {
        return rN;
    }
    
    if (rN == NULL) {
        return lN;
    } else
    return node;
}