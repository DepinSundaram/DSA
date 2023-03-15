#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


/*

Time Complexity: O(N)

Space Complexity: O(H)       (H -> Height of the Tree)
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

void Recursive(struct node* root, int level, vector<int>& ds) {
    if (root == NULL) {
        return;
    }
    if (ds.size() == level) {
        ds.push_back(root->data);
    }
    Recursive(root->left, level + 1, ds); // for RV view Recursive(root->right, level + 1, ds);
    Recursive(root->right, level + 1, ds); // for RV view Recursive(root->left, level + 1, ds);
    
}
vector<int> LeftView(struct node* root) {
    vector<int> res;
    Recursive(root, 0, res);
    return res;
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

  vector < int > leftview;
  leftview = LeftView(root);

  cout << "The Left view is: ";
  for (int i = 0; i < leftview.size(); i++) {
    cout << leftview[i] << " ";
  }

  return 0;
}