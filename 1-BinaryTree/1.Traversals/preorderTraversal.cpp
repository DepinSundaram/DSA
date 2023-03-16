#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/*
Time Complexity: O(N).

Reason: We are traversing N nodes and every node is visited exactly once.

Space Complexity: O(N)

Reason: In the worst case, (a tree with every node having a single right child and left-subtree, follow the video attached below to see the illustration), the space complexity can be considered as O(N).
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
void IterativePreorder(struct node* node, vector<int>& po) {

    stack<struct node*> st;
    st.push(node);

    while(!st.empty()) {
        struct node* top = st.top();
        st.pop();
        po.push_back(top->data);
        if (top->right) { // imp
            st.push(top->right);
        }
        if (top->left) {
            st.push(top->left);
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
  IterativePreorder(root, inOrder);

  cout << "The PreOr Traversal is : ";
  for (int i = 0; i < inOrder.size(); i++) {
    cout << inOrder[i] << " ";
  }
  return 0;
}