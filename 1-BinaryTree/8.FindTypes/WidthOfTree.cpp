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
/*
The maximum width of the Binary Tree is 8

Time Complexity: O(N)

Reason: We are doing a simple level order traversal. The inner loop simply traverses the nodes level-wise and doesn’t add to the complexity.

Space Complexity: O(N)
*/
int widthOfBinaryTree(struct node* root) {
    if (root == NULL)
        return 0;
    queue<pair<node*, int> > q;

    q.push({root, 0});
    int ans = 0;
    while (!q.empty()) {
        int size = q.size();
        int minn = q.front().second;

        int first, last;

        for (int i = 0; i < size; ++i) {
            int curr_id = q.front().second - minn;
            struct node* temp = q.front().first;
            q.pop();
            if (i == 0) {
                first = curr_id;
            }
            if(i == size - 1) {
                last = curr_id;
            }
            if(temp->left) {
                q.push({temp->left, curr_id*2+1});
            }
            if(temp->right) {
                q.push({temp->right, curr_id*2+2});
            }
        }
        ans = max(ans, last - first + 1);
    }

    return ans;
}
int main() {

    struct node * root = newNode(1);
    root -> left = newNode(3);
    root -> left -> left = newNode(5);
    root -> left -> left -> left = newNode(7);
    root -> right = newNode(2);
    root -> right -> right = newNode(4);
    root -> right -> right -> right = newNode(6);

    int maxWidth = widthOfBinaryTree(root);
    cout << "The maximum width of the Binary Tree is " << maxWidth;

  return 0;

    return 0;
}