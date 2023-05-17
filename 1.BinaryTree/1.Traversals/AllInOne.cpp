#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;


/*
Output:

The preorder Traversal is: 1 2 4 5 3 6 7
The inorder Traversal is: 4 2 5 1 6 3 7
The postorder Traversal is: 4 5 2 6 7 3 1

Time Complexity: O(N)

Reason: We are visiting every node thrice therefore time complexity will be O(3*N), which can be assumed as linear time complexity.

Space Complexity: O(N)

Reason: We are using three lists and a stack to store the nodes. The time complexity will be about O(4*N), which can be assumed as linear time complexity.
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

vector<vector<int> > AllTraversals(struct node* head) {
    vector<int> pre, post, in;
    stack<pair<struct node*, int> > st;
    vector<vector<int> > ans;
    //st.push({head, 1});
    st.push(std::make_pair(head, 1));
    if (head == NULL) return ans;

    while(!st.empty()) {
        auto it = st.top();
        st.pop();
        if (it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left) {
                st.push(std::make_pair(it.first->left, 1));
            }

        } else if (it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right) {
                st.push(std::make_pair(it.first->right, 1));
            }
        } else {
            post.push_back(it.first -> data);
        }

    }

    ans.push_back(pre);
    ans.push_back(post);
    ans.push_back(in);

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
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> right = newNode(3);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);

    vector<vector<int> > allTraversals= AllTraversals(root);

    cout << "The bottom view is: ";
    for (auto& vec : allTraversals) {
        for (auto order : vec) {
            std::cout << order << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}