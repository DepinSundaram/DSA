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

/**
 * The function finds the lowest common ancestor of two nodes in a binary tree.
 * 
 * @param root The root node of the binary tree.
 * @param p The first node for which we want to find the lowest common ancestor (LCA) in the binary
 * tree.
 * @param q The parameter "q" in the given code represents a node in a binary tree. It is used to find
 * the lowest common ancestor (LCA) of two nodes "p" and "q" in the binary tree.
 * 
 * @return a pointer to the lowest common ancestor (LCA) of two nodes, p and q, in a binary tree with
 * root node "root".
 */
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
