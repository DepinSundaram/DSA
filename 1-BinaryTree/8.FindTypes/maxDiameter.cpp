#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    node(int val) : data(val) {
        left = right = NULL;
    }
};

/*
Time Complexity: O(N) 

Space Complexity: O(1) Extra Space + O(H) Recursion Stack space (Where “H”  is the height of binary tree )  
*/

int CalculateMaxDiaUsingHeight(node* root, int& dia) {
    if (root == NULL) {
        return 0;
    }

    int lh = CalculateMaxDiaUsingHeight(root->left, dia);
    int rh = CalculateMaxDiaUsingHeight(root->right, dia);
    dia = max(dia, lh + rh);
    return 1 + max(lh, rh);
}

int maxDia(node* root) {
    int dia = 0;
    CalculateMaxDiaUsingHeight(root, dia);
}

struct node * newNode(int data) {
    struct node * node = (struct node * ) malloc(sizeof(struct node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;

    return (node);
}


int main() {
    struct node * root = newNode(-10);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);

    int answer = maxDia(root);
    cout << "The Max Path Sum for this tree is " << answer;

    return 0;
}
