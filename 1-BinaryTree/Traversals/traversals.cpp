/*

1) BFS                  2) DFS (Recursion)
Level Wise                  i) InOrder (L-Root-R)
(Queue and vector)         ii) PreOrder (Root-L-R)
                          iii) PostOrder (L-R-Root)


T C : O(N)
S C : Oxilary space of height of tree / O(N)



            1
        2        3
    4     5    6    7 
*/



#include <iostream>
#include <vector>
#include <queue>
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val) {
        left = right = NULL;
    }
};


std::vector< std::vector<int> > BFS(Node* node)
{
    std::vector< std::vector<int> > BFSorder;
    if (!node) {
        return BFSorder;
    }

    std::queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
        int size = q.size();
        std::vector<int> level;

        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }

            level.push_back(node->data);
        }
        BFSorder.push_back(level);
    }
}


void DFSPreOrder(Node* node)
{
    if (!node) {
        return;
    }

    std::cout << node->data << std::endl;
    DFSPreOrder(node->left);
    DFSPreOrder(node->right);

}