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
vector < vector < int > > findVertical(struct node* head) {
    map<int, map<int, multiset<int> > > mpp;

    queue<pair<node*, pair<int, int> > > q;

    q.push({head, {0, 0}}); 
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        node* temp = p.first;
        //x -> vertical , y->level
        int x = p.second.first;
        int y = p.second.second;

        mpp[x][y].insert(temp->data);

        if (temp->left) {
            q.push({temp->left, {x - 1, y + 1}});
        }

        if (temp->right) {
            q.push({temp->right, {x + 1, y + 1}});
        }
    }

    vector<vector<int> > ans;
    for (auto p : mpp) {
        vector<int> col;
        for (auto q : p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(10);
  root -> left -> left -> right = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(3);
  root -> right -> left = newNode(9);
  root -> right -> right = newNode(10);

  vector < vector < int > > verticalTraversal;
  verticalTraversal = findVertical(root);

  cout << "The Vertical Traversal is : " << endl;
  for (auto vertical: verticalTraversal) {
    for (auto nodeVal: vertical) {
      cout << nodeVal << " ";
    }
    cout << endl;
  }
  return 0;
}