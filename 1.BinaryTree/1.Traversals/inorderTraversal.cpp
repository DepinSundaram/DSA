#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/*
Time Complexity: O(N).

Reason: We are traversing N nodes and every node is visited exactly once.

Space Complexity: O(N)

Reason: In the worst case (a tree with just left children), the space complexity will be O(N).
*/
struct node
{
    int data;
    node* left;
    node* right;
    node(int val) : data(val) {
        left = right = NULL;
    }
};

void IterativeInorder(struct node* head, vector<int>& inor) {
    stack<struct node*> st;

    struct node* node = head;
    while(true) {
        if (node) {
            st.push(node);
            node = node->left;
        } else {
            if (st.empty() == true) break;

            node = st.top();
            st.pop();
            inor.push_back(node->data);
            node = node->right;
        }

    }
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
  root -> left -> right -> left = newNode(8);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> right = newNode(10);

  vector < int > inOrder;
  IterativeInorder(root, inOrder);

  cout << "The inOrder Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }
  return 0;
}