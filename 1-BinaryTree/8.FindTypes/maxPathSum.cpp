#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
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
Time Complexity: O(N).

Reason: We are doing a tree traversal.

Space Complexity: O(N)

Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).
*/

int findMaxPathSum(node* root, int& maxi) {
    if (root == NULL) {
        return 0;
    }

    int leftMaxSum = max(0, findMaxPathSum(root->left, maxi));
    int rightMaxSum = max(0, findMaxPathSum(root->right, maxi));
    int val = root->data;
    maxi = max(maxi, leftMaxSum + rightMaxSum + val);
    return max (leftMaxSum, rightMaxSum) + val;
}

int maxPathSum(node * root) {
    int maxi = INT_MIN;
    findMaxPathSum(root, maxi);
    return maxi;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(-10);
  root -> left = newNode(9);
  root -> right = newNode(20);
  root -> right -> left = newNode(15);
  root -> right -> right = newNode(7);

  int answer = maxPathSum(root);
  cout << "The Max Path Sum for this tree is " << answer;

  return 0;
}
