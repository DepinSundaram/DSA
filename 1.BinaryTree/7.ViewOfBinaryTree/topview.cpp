#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;


/*
Time Complexity: O(N)

Space Complexity: O(N)
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
vector<int> TopView(struct node* root) {
    vector<int> ans;

    if (root == NULL) return ans;

    map<int, int> mpp;
    queue<std::pair<struct node*, int> > q;
    q.push({root, 0});

    while(!q.empty()) {
        auto it = q.front();
        q.pop();

        struct node* cur = it.first;
        int line = it.second;

        if (mpp.find(line) == mpp.end()) {
            mpp[line] = cur->data;
        }

        if (cur->left) {
            q.push({cur->left, line -1});
        }
        if (cur->right) {
            q.push({cur->right, line + 1});
        }
    }

    for (auto it : mpp) {
        ans.push_back(it.second);
    }

    return ans;
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

    vector < int > Topview;
    Topview = TopView(root);

    cout << "The top view is: ";
    for (int i = 0; i < Topview.size(); i++) {
        cout << Topview[i] << " ";
    }

    return 0;
}