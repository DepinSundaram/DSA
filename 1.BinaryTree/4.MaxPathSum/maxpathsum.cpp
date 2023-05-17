#include <iostream>
// val +  (leftPathMax + RightPathMax)

/* Time Complexity: O(N).
Reason: We are doing a tree traversal.

S C 
Space Complexity: O(N)
Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).
*/
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val) {
        left = right = NULL;
    }
};

struct Node * newNode(int data) {
  struct Node * node = (struct Node * ) malloc(sizeof(Node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;
  return (node);
}

class Solution {
public:
    int maxPathSum(Node* root) {
        int maxsumpath = 0;
        Path(root, maxsumpath);
        return maxsumpath;
    }

private:
    int Path(Node* node, int& maxsumpath) {

        if (!node) {
            return 0;
        }

        int lS = std::max(0, Path(node->left, maxsumpath)); // 0 for negative value
        int rS = std::max(0, Path(node->right, maxsumpath));

        maxsumpath = std::max(maxsumpath, lS + rS + node->data);

        return std::max(lS, rS) + node->data;
    }
};