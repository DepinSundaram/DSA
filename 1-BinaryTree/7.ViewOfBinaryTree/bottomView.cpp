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

vector<int> BottomView(struct node* head) {
    vector<int> ans;

    if (head == NULL) {
        return ans;
    }
    map<int, int> mpp; // stores in sorted order
    queue<std::pair<struct node*, int> > q;

    q.push({head, 0});

    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        struct node* node = it.first;
        int line = it.second;
        mpp[line] = node->data;

        if (node->left != NULL) {
            q.push({node->left, line - 1});
        }
        if (node->right != NULL) {
            q.push({node->right, line + 1});
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

    vector < int > bottomview;
    bottomview = BottomView(root);

    cout << "The bottom view is: ";
    for (int i = 0; i < bottomview.size(); i++) {
        cout << bottomview[i] << " ";
    }

    return 0;
}