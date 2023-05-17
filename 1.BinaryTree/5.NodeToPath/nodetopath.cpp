#include <iostream>
#include <vector>


/*
Time Complexity: O(N)

Reason: We are doing a simple tree traversal.

Space Complexity: O(N)

Reason: In the worst case (skewed tree), space complexity can be O(N).
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


struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

bool getPath(struct node* node, std::vector<int>& arr, int nodeVal)
{
    if (!node) {
        return false;
    }

    arr.push_back(node->data);

    if (node->data == nodeVal) {
        return true;
    }

    bool lP = getPath(node->left, arr, nodeVal);
    bool rP = getPath(node->right, arr, nodeVal);

    if (lP || rP) {
        return true;
    }
    arr.pop_back();
    return false;
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(6);
  root -> left -> right -> right = newNode(7);
  root -> right = newNode(3);

  std::vector<int> arr;

  bool res;
  res = getPath(root, arr, 7);

  std::cout << "The path is ";
  for (auto it: arr) {
    std::cout << it << " ";
  }

  return 0;
}

