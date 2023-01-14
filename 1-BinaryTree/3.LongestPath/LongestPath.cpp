#include <iostream>

// Formula :
// MAX (maxi , LEFTHEIGHT + RIGHTHEIGHT)
 
// Use recursion (DFS)

/*
https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/
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

int maxi = INT_MIN;
int MaxHeight(Node* root)
{
    if (!root) {
        return 0;
    }

    int lH = MaxHeight(root->left);
    int rH = MaxHeight(root->right);

    return 1 + std::max(lH, rH);
}

// BF O(N^2)

void findMaxPath1(Node* node)
{
    if (!node) {
        return;
    }

    int lH = MaxHeight(node->left);
    int rH = MaxHeight(node->right);
    maxi = std::max(maxi, lH + rH);   // Find the max path at each node can tell the max path or dia
    findMaxPath1(node->left);
    findMaxPath1(node->right);
}


// O(N)

class Solution {
public:
    int diameterOfBinaryTree(Node* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(Node* node, int& diameter) {

        if (!node) {
            return 0;
        }

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = std::max(diameter, lh + rh);

        return 1 + std::max(lh, rh);
    }
};