#include <iostream>
#include <vector>
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

node* insertBST(node* root, int val)
{
    if (root == nullptr) {
        return new node(val);
    }

    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }

    return root;
}

node* kthLargest(node* root, int& val) {
    if (root == nullptr) return nullptr;

    node* right = kthLargest(root->right, val);
    if (right !=NULL) {
        return right;
    }
    val--;
    if (val == 0) {
        return root;
    }

    return kthLargest(root->left, val);
}

node* kthSmallest(node* root, int& val) {
    if (root == nullptr) return nullptr;

    node* left = kthSmallest(root->left, val);
    if (left !=NULL) {
        return left;
    }
    val--;
    if (val == 0) {
        return root;
    }

    return kthSmallest(root->right, val);
}


node* InorderSuccessor(node* node, int val) {

    struct node* succ = nullptr;
    while (node != nullptr) {
        if (node->data <= val) {
            node = node->right;
        } else {
            succ = node;
            node = node->left;
        }
    }
    return succ;
}

node* InorderPred(node* node, int val) {

    struct node* pred = nullptr;
    while (node != nullptr) {
        if (node->data < val) {
            pred = node;
            node = node->right;
        } else {
            node = node->left;
        }
    }
    return pred;
}

int main() {
    int arr[] = {10,40,45,20,25,30,50},i;


    int k = 3;
    node* root = nullptr;

    for (int i = 0; i < 7; i++) {
        root = insertBST(root, arr[i]);
    }
	cout<<"\n";
/*	
	int p=k;
	node* large=kthLargest(root,k);
	k=p;
	node* small=kthSmallest(root,k);
	if(large==NULL)
	{
		cout<<"Invalid input"<<"\n";
	}
	else
	cout<<"kth largest element is  "<<large->data<<"\n";
	
	if(small==NULL)
	{
		cout<<"Invalid input"<<"\n";
	}
	else
	{
		cout<<"kth smallest element is  "<<small->data<<"\n";
	}
*/
   // auto succ = InorderSuccessor(root, 45);
    //std::cout << succ->data;
    auto pred = InorderPred(root, 20);
    std::cout << pred->data;

    
}