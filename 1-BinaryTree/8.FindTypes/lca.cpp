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

node* LCA(node* root, node* p, node* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    node* left = LCA(root->left, p, q);
    node* right = LCA(root->right, p, q);


    if (left == NULL) {
        return right;
    } else if (right == NULL) {
        return left;
    } else {
        return root;
    }

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

  node* res = LCA(root, root -> right -> left,  root -> left);
  cout << "The LCA  is " << res->data;

  return 0;
}
