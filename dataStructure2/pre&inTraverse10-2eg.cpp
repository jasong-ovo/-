#include <iostream>
#include <cstdio>
#include <string>

using namespace std;


struct treeNode
{
    char data;
    treeNode* leftChild;
    treeNode* rightChild;
    treeNode(char d){
        data = d;
        leftChild = NULL;
        rightChild = NULL;
    }
};


void postOrder(treeNode *root){
    if (root == NULL) return;
    postOrder(root->leftChild);
    postOrder(root->rightChild);
    printf("%c", root->data);
}

//debug 
void inOrder (treeNode *root){
    if (root == NULL) return;
    inOrder(root->leftChild);
    printf("%c", root->data);
    inOrder(root->rightChild);
}

void preOrder(treeNode *root){
    if (root == NULL) return;
    printf("%c", root->data);
    preOrder(root->leftChild);
    preOrder(root->rightChild);
}

treeNode * bulidTree(string preO, string inO) {
    char rootData = preO[0];
    treeNode * tree = new treeNode(rootData);
    if (preO.length() == 1) {
        return tree;
    }
    int spliter;
    spliter = inO.find(preO[0]);
    // printf("spliter:%d\n", spliter);
    string inOsub, preOsub;
    int lenLeft, lenRight;
    lenLeft = spliter;
    lenRight = preO.length() - spliter - 1;
    //left
    if (lenLeft > 0){
        inOsub = inO.substr(0, lenLeft);
        // cout << inOsub << endl;
        preOsub = preO.substr(1, lenLeft);
        // cout << preOsub <<endl;
        tree->leftChild = bulidTree(preOsub, inOsub);
    }

    //right
    if (lenRight > 0){
        inOsub = inO.substr(spliter+1, lenRight);
        preOsub = preO.substr(lenLeft+1, lenRight);
        tree->rightChild = bulidTree(preOsub, inOsub); 
    }

    return tree;
}

int main(){
    string preO, inO;
    getline(cin, preO);
    getline(cin, inO);
    treeNode *root;
    root = bulidTree(preO, inO);
    postOrder(root);
    return 0;
}