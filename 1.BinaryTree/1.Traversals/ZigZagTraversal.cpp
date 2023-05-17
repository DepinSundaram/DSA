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


void ZigZagTraversal(node* root, vector<vector<int> >& output) {

    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    bool right2left = true;
    while(!q.empty()) {
        int size = q.size();
        vector<int> n(size);
        for (int i = 0; i < size; ++i) {
            int idx = (right2left == true) ? i : (size - i - 1);
            node* temp = q.front();
            q.pop();
            n[idx] = temp->data;
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        right2left = !right2left;
        output.push_back(n);
        n.clear();
    }
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
    root -> left->right = newNode(5);
    root -> left->left = newNode(4);
    root -> left->left->left = newNode(9);

    root->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(10);

    vector < vector<int> > arr;
    ZigZagTraversal(root, arr);


    for (auto ar : arr) {
        for (auto e : ar) {
            std::cout << e << " ";
        }
    }

}