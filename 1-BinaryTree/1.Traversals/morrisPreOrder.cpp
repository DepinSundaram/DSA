#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


// reduces space complexity to O(1) time ~O(N)

struct node
{
    int data;
    node* left;
    node* right;
    node(int val) : data(val) {
        left = right = NULL;
    }
};


vector<int> PreorderTraversal(struct node* head) {
    struct node* cur = head;
    vector<int> po;
    while (cur != NULL) {
        if (cur->left == NULL) {
            po.push_back(cur->data);
            cur = cur->right;
        } else {
            node* prev = cur->left;
            while (prev->right && prev->right !=cur) {
                prev = prev->right;
            }

            if (prev->right == NULL) {
                prev->right = cur;
                po.push_back(cur->data);
                cur = cur->left;
            } else {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }

    return po;
}
struct node* newNode(int val) {
    struct node* node = (struct node*) malloc (sizeof(struct node));
    node->data = val;
    node->left = node->right = nullptr;
    return node;
}
int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> right = newNode(6);

  vector < int > preorder;
  preorder = PreorderTraversal(root);

  cout << "The Preorder Traversal is: ";
  for (int i = 0; i < preorder.size(); i++) {
    cout << preorder[i] << " ";
  }

  return 0;
}