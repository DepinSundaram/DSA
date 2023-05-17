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

/*
The path is 1 2 5 7

Time Complexity: O(N)

Reason: We are doing a simple tree traversal.

Space Complexity: O(N)

Reason: In the worst case (skewed tree), space complexity can be O(N).
*/
bool getPath(struct node* root, vector<int>& arr, int val) {
    if (!root) {
        return false;
    }
    arr.push_back(root->data);
    if (root->data == val) {
        return true;
    }

    if ( getPath(root->left, arr, val) || 
        getPath(root->right, arr, val) ) {
        return true;
    }
  // required node does not lie either in the
  // left or right subtree of the current node
  // Thus, remove current node's value from
  // 'arr'and then return false  
    arr.pop_back();
    return false;

}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

    struct node * root = newNode(1);
    root -> left = newNode(2);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> left -> right -> left = newNode(6);
    root -> left -> right -> right = newNode(7);
    root -> right = newNode(3);

    vector < int > arr;

    getPath(root, arr, 7);

    cout << "The path is ";
    for (auto it: arr) {
        cout << it << " ";
    }

    return 0;
}