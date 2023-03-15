#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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



struct node* newNode(int val) {
    struct node* node = (struct node*) malloc (sizeof(struct node));
    node->data = val;
    node->left = node->right = nullptr;
    return node;
}


void IterativePostorder(struct node* head, vector<int>& postO) {
    
}
int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(8);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> right = newNode(10);

  vector < int > inOrder;
  IterativePostorder(root, inOrder);

  cout << "The Post Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }
  return 0;
}