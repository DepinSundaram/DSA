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



bool IsLeafNode(node* root) {
  return !root -> left && !root -> right;
}
bool isLeaf(node * root) {
  return !root -> left && !root -> right;
}
void LeftTraversal(node* root, vector<int>& lans) {

    node* cur = root->left;
    while(cur) {
        if (!IsLeafNode(cur)) {
            lans.push_back(cur->data);
        }

        if (cur->left) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
}

void RightTraversal(node* root, vector<int>& rans) {

    node* cur = root->right;
    vector<int> temp;
    while (cur) {
        if (!IsLeafNode(cur)) {
            temp.push_back(cur->data);
        }

        if (cur->right) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }

    for (int i = temp.size() - 1; i >= 0; --i) {
        rans.push_back(temp[i]);
    }
  }

void addLeaves(node* root, vector<int>& leaves) {
    if (IsLeafNode(root)) {
        leaves.push_back(root->data);
        return;
    }
    if (root->left) addLeaves(root->left, leaves);
    if (root->right) addLeaves(root->right, leaves);

}


vector < int > BorderTraversals(struct node* root) {
        vector < int > ans;

        if (root == nullptr) {
            return ans;
        }

        if (!IsLeafNode(root)) {
            ans.push_back(root->data);
        }

    LeftTraversal(root, ans);
    addLeaves(root, ans);
    RightTraversal(root, ans);

    return ans;

  }
int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  root -> left -> left -> right -> left = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(7);
  root -> right -> right = newNode(8);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> left -> left = newNode(10);
  root -> right -> right -> left -> right = newNode(11);

   vector < int >  bo;
   bo = BorderTraversals(root);

  cout << "The Vertical Traversal is : " << endl;
  for (auto b: bo) {
      cout << b << " ";
  }
  return 0;
}