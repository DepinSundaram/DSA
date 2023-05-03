#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node{
	int data;
	node *left,*right;
	node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};
struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}
node* ConstructTree(vector<int>& preO, int pstart, int pEnd,
				vector<int>& inO, int inStart, int inEnd, map<int, int>& mpp) {


    if (pstart > pEnd || inStart > inEnd) return nullptr;

	node* root =  newNode(preO[pstart]);

	int eIdx = mpp[root->data];
	int nIdx = eIdx - inStart; 

	root->left = ConstructTree(preO, pstart + 1, pstart + nIdx, inO, inStart, nIdx - 1, mpp );
	root->right = ConstructTree(preO, pstart + eIdx + 1, pEnd, inO, nIdx + 1, inEnd, mpp);
	return root;
}
node* buildTree(vector<int>& preO, vector<int>& inO) {
	node* root =nullptr;

	map<int, int> mpp;

	for (int i = 0; i < inO.size(); i++) {
		mpp[inO[i]] = i;
	}
	return ConstructTree(preO, 0, preO.size(), inO, 0, inO.size(), mpp);
}



int main() {
  vector<int> preorder{10,20,40,50,30,60};
  vector<int> inorder{40,20,50,10,60,30};
  node * root = buildTree(preorder, inorder);
}