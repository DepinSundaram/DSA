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
.Time Complexity: O(N)

Assumption: Hashmap returns the answer in constant time.

Space Complexity: O(N)

Reason: We are using an external hashmap of size ‘N’.
*/

node* ConstructTree(vector<int>& preO, int preStart, int preEnd,
                    vector<int>& inO, int inStart, int inEnd, map<int, int>& mp){
    
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }

    node* root = newNode(preO[preStart]);
    int elem = mp[root->data];
    int nElem = elem - inStart;

    root->left = ConstructTree(preO, preStart + 1, preStart + nElem, inO, inStart, elem - 1, mp);
    root->right = ConstructTree(preO, preStart + nElem + 1, preEnd, inO, elem + 1, inEnd, mp);       
    return root;
}

node* buildTree(vector<int>& preO, vector<int>& inO) {
    int preStart = 0, preEnd = preO.size() - 1;
    int inStart = 0, inEnd = inO.size() - 1;


    map<int, int> mp;
    for (int i = inStart; i<=inEnd; i++)  {
        mp[inO[i]] = i;
    }

    return ConstructTree(preO, preStart, preEnd, inO, inStart, inEnd, mp);  
}

void PrintInOrder(node* root) {
    if (!root) {
        return;
    }
    node* cur = root;
    stack<node*> st;
    vector<int> Io;
    while(true) {
        if (cur) {
            st.push(cur);
            cur = cur->left;
        } else {
            if (st.empty() == true) break;
            node* temp = st.top();
            st.pop();
            Io.push_back(temp->data);
            cur = temp->right;
        }
    }

    for (auto i : Io) {
        printf("%d ", i);
    }
}
int main() {

  vector<int> preorder{10,20,40,50,30,60};
  vector<int> inorder{40,20,50,10,60,30};
  node * root = buildTree(preorder, inorder);


  PrintInOrder(root);
  return 0;
}