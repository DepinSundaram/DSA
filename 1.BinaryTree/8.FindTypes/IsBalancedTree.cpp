// Balanced tree (abs difference b/w left tree subtree height and right subtree height should not exeeds 1)
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

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


struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}



int IsBalanced(node* head) {
    if (head == nullptr) {
        return 0;
    }


    int Lheight = IsBalanced(head->left);

    if (Lheight == -1) {
        return -1;
    }
    int Rheight = IsBalanced(head->right);
    if (Rheight == -1) {
        return -1;
    }

    if (abs(Lheight - Rheight) > 1) {
        return -1;
    }
    return 1 + max(Lheight, Rheight);


}
int main() {

    struct node * root = newNode(4);
    root->left = newNode(7);
    root->right = newNode(8);
    root->right->right = newNode(0);
    root->right->left = newNode(1);
    root->right->left->left = newNode(3);
    root->right->left->right = newNode(5);


    if (IsBalanced(root) != -1)
    {
        std::cout << true;
        return 0;
    }

    std::cout << false;

}