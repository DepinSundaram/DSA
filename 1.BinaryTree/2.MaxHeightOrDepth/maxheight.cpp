#include <iostream>

// Formula : 1 + max(Left, Right)
// Use recursion (DFS)

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val) {
        left = right = NULL;
    }
};

int MaxHeight(Node* root)
{
    if (!root) {
        return 0;
    }

    int lH = MaxHeight(root->left);
    int rH = MaxHeight(root->right);

    return 1 + std::max(lH, rH);
}
