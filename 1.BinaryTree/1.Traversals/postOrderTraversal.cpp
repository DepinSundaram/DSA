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


vector < int > postOrderTrav(node * cur, vector<int>& postOrder ) {

  if (cur == NULL) return postOrder;

  stack < node * > st;
  while (cur != NULL || !st.empty()) {

    if (cur != NULL) {
      st.push(cur);
      cur = cur -> left;
    } else {
      node * temp = st.top() -> right;
      if (temp == NULL) {
        temp = st.top();
        st.pop();
        postOrder.push_back(temp -> data);
        while (!st.empty() && temp == st.top() -> right) {
          temp = st.top();
          st.pop();
          postOrder.push_back(temp -> data);
        }
      } else cur = temp;
    }
  }
  return postOrder;
}

int main() {

  struct node * root = newNode(1);
  root->left = newNode(2);
  root->left->left = newNode(3);
  root->left->right = newNode(4);
  root->right = newNode(5);


  vector < int > PostOrder;
  postOrderTrav(root, PostOrder);

  cout << "The Post Traversal is : ";
  for (int i = 0; i < PostOrder.size(); i++) {
    cout << PostOrder[i] << " ";
  }
  return 0;
}