#include <iostream>
#include <vector>
using namespace std;




struct node{
    int data;
    node* left;
    node* right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};


struct llnode{
    int data;
    llnode* next;
    llnode(int val) : data(val), next(nullptr) {}
};



void InsertInBST(node** bstroot, int element){

    if (*bstroot == nullptr) {
        *bstroot = new node(element);
        return;
    }
    if ((*bstroot)->data > element) {
        InsertInBST(&(*bstroot)->left, element);
    } else if ((*bstroot)->data < element){
        InsertInBST(&(*bstroot)->right, element);
    }
}


void InsertLinkedList(llnode** root, int element) {
    if (*root == nullptr) {
        *root = new llnode(element);
        return;
    }
    llnode* temp = *root;
    while(temp->next !=nullptr) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        temp->next = new llnode(element);
    }
}
int main()
{
    vector<int> arr{5,4, 3, 6, 7, 8};
    node* bst(nullptr);
    /*for (auto e : arr) {
        InsertInBST(&bst, e);
    }*/

    llnode* ll(nullptr);
    for (auto e : arr) {
        InsertLinkedList(&ll, e);
    }
    cout << " Here";

}

/*
#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct info
{

     char **name; // rohit rahul karan
     char **city; // noida delhi

}Info;

char* TrimSpace(char* input) { 
    int i = 0;
    int j = 0;
    char* inputWithoutSpace = new char[100];
    while(input[i] != '\0') {
        if (input[i] == ' ') {
            continue;
            i++;
        }
        inputWithoutSpace[j] = input[i];
        j++;
        i++;
    }
    
    return inputWithoutSpace;
}

void parse_and_fill(char *inputWithoutSpace,  info m_info)
{
    // name = Rohit; city=Noida;
    // name=
    int i = 0;
    m_info.name = new char*[100];
    int idx = 0;
    while(inputWithoutSpace[i] != NULL) {
        if (inputWithoutSpace[i] == 'n' && inputWithoutSpace[i+4] == '=') { // 
            char name[100];
            int j = 0;
            i = i + 5;
            m_info.name[idx] = new char[50];  
            while(inputWithoutSpace[i] != ';') {
                m_info.name[idx][j]= inputWithoutSpace[i];
                j++;
                i++;
            }
        } else if (inputWithoutSpace[i] == 'c' && inputWithoutSpace[i+4] == '=') {
            char city[100];
            int j = 0;
            i = i + 5;
            m_info.city[idx] = new char[50];  
            while(inputWithoutSpace[i] != ';') {
                m_info.city[idx][j]= inputWithoutSpace[i];
                j++;
                i++;
            }
        }
        i++;
    }
}
int main() {
    char *p = “name = Rohit; city=Noida;name=Rahul;name=Karan;city   =  Delhi”; //Assume string can have 100 key value pair O(Len(N))
    
    char *str_Withoutspace = TrimSpace(p);
    
    // Parse
    info m_res;
    parse_and_fill(str_Withoutspace, m_res);
    return 0;
}
// Your old code in c has been preserved below.
// #include <math.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// /*
// 1. Given a ‘;’ separated “key = value” pair, accumulate all the values corresponding to their keys in a structure. 
// struct info
// {

//     char **name; // rohit rahul karan
//     char **city; // noida delhi

// }Info;
// int main()
// {

//     char *p = “name = Rohit; city=Noida;name=Rahul;name=Karan;city   =  Delhi”; //Assume string can have 100 key value pair O(Len(N))
        // trim all space;
        // start parse and find name=''; || city=''
        /*
            if name
            char *_name = new char[];
            Info.name = &_name;
        */
        
     
//      //parse and fill info struct 
//      //call your function here to parse and fill the struct …
//       parse_and_fill()//choose your argument

//      //print name and city values filled in the Info structure.
//        print_values();
       
//        output:
//          Rohit
//          Rahul
//          Karan
//          Noida
//          Delhi


//     return 0;

// }
// */
// int main() {
    

//     return 0;
// }

*/