#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;


struct Node {
    int data;
    struct Node* left, *right;
    Node(int num) : data(num), left(nullptr), right(nullptr) {}
};

struct Node* newNode(int data) {
    struct Node* node = new Node(data);
    return node;
}


vector<int> LevelOrderTraversal(struct Node* head) {

    if (head == nullptr) {
        return vector<int> {};
    }
    queue<Node*> q;
    q.push(head);
    vector<int> res;

    while(!q.empty()) {
        Node* cnode = q.front();
        q.pop();
        res.push_back(cnode->data);
        if (cnode->left) {
            q.push(cnode->left);
        }

        if (cnode->right) {
            q.push(cnode->right);
        }
    }

    return res;
}

vector<int> PreOrderTraversal(struct Node* head) {

    if (head == nullptr) {
        return vector<int>{};
    }

    stack<Node*> st;

    st.push(head);
    vector<int> res;

    while (!st.empty()) {
        Node* temp = st.top();
        st.pop();
        res.push_back(temp->data);
        if (temp->right) {
            st.push(temp->right);
        }
        if (temp->left) {
            st.push(temp->left);
        }
    }

    return res;
}


vector<int> InOrderTraversal(Node* node) {
    stack<Node*> st;
    vector<int> res;
    Node* temp = node;
    while (1) {
        if (temp) {
            st.push(temp);
            temp = temp->left;
        } else {
            if (st.empty()) break;
            temp = st.top();
            st.pop();
            res.push_back(temp->data);
            temp = temp->right;
        }
    }

    return res;
}


vector<int> PostOrderTraversal(Node* node) {
    stack<Node*> st1;
    stack<Node*> st2;

    vector<int> res;

    st1.push(node);

    while(!st1.empty()) {
        node = st1.top();
        st1.pop();
        st2.push(node);

        if (node->left != NULL) {
            st1.push(node->left);
        }
        if (node->right != NULL) {
            st1.push(node->right);
        }
    }

    while (!st2.empty()) {
        res.push_back(st2.top()->data);
        st2.pop();
    }
    return res;
}


int heightOfTree(struct Node* node) {
    if (node == nullptr) {
        return 0;
    }

    int lh = heightOfTree(node->left);
    int rh = heightOfTree(node->right);

    return 1 + max(lh, rh);
}

int isDFSHeight(struct Node* node) {
    if (node == NULL) return 0;

    int lh = isDFSHeight(node->left);

    if (lh == -1) {
        return -1;
    }

    int rh = isDFSHeight(node->right);

    if (rh == -1) {
        return -1;
    }

    if (abs(lh - rh) > 1) {
        return -1;
    } 

    return 1 + max(lh, rh);


}
bool IsBalancedTree(struct Node* node) {

    return isDFSHeight(node) != -1;
}


int DiameterOfTree(struct Node* node, int *diameter) {

    if (node == nullptr) {
        return 0;
    }

    int lh = DiameterOfTree(node->left, diameter);
    int rh = DiameterOfTree(node->right, diameter);

    *diameter = max(*diameter, lh + rh);

    return 1 + max(lh, rh);

}

int FindMinSumFromFree(Node* root, int& maxSum) {
    if (root == nullptr) {
        return 0;
    }
    int lS = max(0, FindMinSumFromFree(root->left, maxSum));
    int rS = max(0, FindMinSumFromFree(root->right, maxSum));
    int val = root->data;
    maxSum = max(maxSum, (lS + rS) + val);
    return max (lS, rS) + val;
}

int calculateMaxSumPath(Node* root) {
    int maxSum = INT_MIN;
    FindMinSumFromFree(root, maxSum);
    return maxSum;
}

vector<vector<int>> VerticalTraversal(Node* root) {

    queue<pair<Node*, pair<int, int>>> qq;
    map<int, map<int, multiset<int>>> node;
    // ver , leve, value
    qq.push({root, {0, 0}});
    while (!qq.empty()) {
        auto p = qq.front();
        qq.pop();

        Node* tempnode = p.first;
        int ver = p.second.first;
        int lev = p.second.second;

        node[ver][lev].insert(tempnode->data);

        if (tempnode->left) {
            qq.push({tempnode->left, {ver - 1, lev + 1}});
        }
    
        if (tempnode->right) {
            qq.push({tempnode->right, {ver + 1, lev + 1}});
        }
    }

    vector<vector<int>> ans;
    // ver {level , val}
    for (auto p : node) {
        vector<int> col;

        for (auto q :  p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        } 
        ans.push_back(col);
    }

    return ans;

}
int main() {
   /* struct Node* root = newNode(1);
    root->left = newNode(2);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> left -> right -> left = newNode(8);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);
    root -> right -> right -> left = newNode(9);
    root -> right -> right -> right = newNode(10);
*/

    //auto res = LevelOrderTraversal(root);
    //auto res = PreOrderTraversal(root);
    //auto res = InOrderTraversal(root);
    //auto res = PostOrderTraversal(root);


      struct Node * root = newNode(1);
        root -> left = newNode(2);
        root -> left -> left = newNode(4);
        root -> left -> right = newNode(10);
        root -> left -> left -> right = newNode(5);
        root -> left -> left -> right -> right = newNode(6);
        root -> right = newNode(3);
        root -> right -> left = newNode(9);
        root -> right -> right = newNode(10);
        auto res = VerticalTraversal(root);
    for (auto row : res) {
        for (auto e : row) {
            std::cout << e << " ";
        }
    }

   // cout << heightOfTree(root);
    //cout << IsBalancedTree(root);
    //int diameter = 0;
    //DiameterOfTree(root, &diameter);
    //auto res = calculateMaxSumPath(root);

}