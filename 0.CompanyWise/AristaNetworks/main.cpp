#include <iostream>

struct node {
    int value;
    node* left;
    node* right;
    node* parent;
};

struct node *newNode(int item)
{
    struct node *temp =  new node;
    temp->value = item;
    temp->left = temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

node* find_min(node* root) {
    if (!root) {
        return nullptr;
    }
    node* cNode = root;

    while (cNode->left) {
        cNode = cNode->left;
    }
   // printf("Min element : %d\n", cNode->value);
    return cNode;
}


node* find_nextInOrder(node* treenode)
{

    if (!treenode) {
        return NULL;
    }
    node* tmp = treenode;
    if (treenode->right) {
        tmp = treenode->right;
        return find_min(tmp);
    } else {
        //no right subtree
        tmp = treenode -> parent;
        while (tmp && tmp->value < treenode->value) {
            if(tmp->parent) {
                tmp = tmp->parent;
            }else {
            return nullptr;
            }

            //printf("New Cand : %d\n", tmp->value);
        }
    }
    return tmp;
}

node* insert(node* n, int val) {

    if (n == NULL)
        return newNode(val);
    
    if (val < n->value) {
        node* lchild = insert(n->left, val);
        n->left = lchild;
        lchild->parent = n;
    } else if (val > n->value) {
        node* rchild = insert(n->right, val);
        n->right = rchild;
        rchild->parent = n;
    }

    return n;
}

node* construct_bst()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    return root;
}

int main() {
    // Find Next to print Inorder
    node* root = construct_bst();
    for (node* n = find_min(root); n !=nullptr; n = find_nextInOrder(n)) {
        printf("%d ", n->value);
    }
}
