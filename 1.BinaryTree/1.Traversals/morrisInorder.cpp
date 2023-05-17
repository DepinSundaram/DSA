#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


// reduces space complexity to O(1)

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
vector<int> InorderTraversal(struct node* head) {
    vector<int> inOrder;

    node* cur = head;

    while (cur != NULL) {
        if (cur->left == NULL) {
            inOrder.push_back(cur->data);
            cur = cur->right;
        } else {
            node* prev = cur->left; // cur move left then extreme right
            while (prev->right !=NULL && prev->right != cur) {
                prev = prev->right;
            }

            if (prev->right == NULL) { // if right node is null 
                                    // assign the right to cur travese down to left to do same
                prev->right = cur;
                cur = cur->left;
            } else { // unlink and push curr
                prev->right = NULL;
                inOrder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }

    return inOrder;
}
int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> right = newNode(6);

  vector < int > Inorder;
  Inorder = InorderTraversal(root);

  cout << "The Preorder Traversal is: ";
  for (int i = 0; i < Inorder.size(); i++) {
    cout << Inorder[i] << " ";
  }

  return 0;
}