#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

struct treeNode {
    char data;
    treeNode *leftChild;
    treeNode *rightChild;
    treeNode(char d){
        data = d;
        leftChild = NULL;
        rightChild = NULL;
    }  
};


void inOrder(treeNode *root){
    if (root == NULL) return;
    inOrder(root->leftChild);
    printf("%c ", root->data);
    inOrder(root->rightChild);
}


treeNode * plantTree(int *position, string str){
    if (str[*position] == '#') 
    {   *position = *position + 1;  
        return NULL;
        }

    treeNode * root = new treeNode(str[*position]);
    *position = *position + 1;
    root -> leftChild = plantTree (position, str);
    root -> rightChild = plantTree (position, str);
    
    return  root;
}


int main(){
    string preOder;
    getline(cin, preOder);
    int left = preOder.length();
    int position = 0;

    // construct the tree
    treeNode* root = plantTree(&position, preOder);
    inOrder(root);

    return 0;
}