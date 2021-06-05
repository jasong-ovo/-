#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

struct treeNode {
    char data;
    treeNode *leftChild;
    treeNode *rightChild;
    treeNode(int d){
        data = d;
        leftChild = NULL;
        rightChild = NULL;
    }
};



//how to compare whether two trees have the same structure
treeNode *insertBST(treeNode *root, char data){
    if (root == NULL) {
        // printf("insert data:%c\n", data);
        return new treeNode(data);
    }
    if (data < root->data) {
        // printf("<\n");
        root->leftChild = insertBST(root->leftChild, data);
    }
    else {
        // printf(">=\n");
        root->rightChild = insertBST(root->rightChild, data);
    }
    return root;
}



void preOrder(treeNode* root, char * str){
    if (root == NULL) return;
    
    //preorder
    //locate
    int n=0;
    while (str[n] != 0) n++;
    str[n] = root->data;
    // printf("%c", str[n]);
    preOrder(root->leftChild, str);
    preOrder(root->rightChild, str);

    return;
}


void inOrder(treeNode* root, char * str){
    if (root == NULL) return;


    //inorder
    inOrder(root->leftChild, str);
    //locate
    int n=0;
    while (str[n] != 0) n++;
    str[n] = root->data;
    // printf("%c", str[n]);
    inOrder(root->rightChild, str);
    return ;
}

// //奇怪的bug
// bool compare(treeNode *a, treeNode *b){
//     // char * preStra;
//     // char * inStra;
//     // char * preStrb;
//     // char * inStrb;
//     // preStra = (char*)malloc(11);
//     // preStrb = (char*)malloc(11);
//     // inStra = (char*)malloc(11);
//     // inStrb = (char*)malloc(11);
//     // memset(preStra, 0, 11);
//     // memset(preStrb, 0, 11);
//     // memset(inStra, 0, 11);
//     // memset(inStrb, 0, 11);
//     char preStra[11], preStrb[11], inStra[11], inStrb[11];

//     preOrder(a, preStra);
//     printf("mark\n");
//     preOrder(b, preStrb);
//     // printf("\n");
//     inOrder(a, inStra);
//     inOrder(b, inStrb);

//     // printf("prestrStd:%s\n", preStra);
//     // printf("prestrTmp:%s\n", preStrb);

//     if (!strcmp(preStra, preStrb) && !strcmp(inStra, inStrb)){
//         return true;
//     }
//     return false;
// }




int main(){
    int N=0;
    scanf("%d", &N);
    getchar();
    string stdTstr;
    getline(cin, stdTstr);
    treeNode * stdRoot;
    stdRoot = NULL;
    for (int i=0; i<stdTstr.size(); i++){
        stdRoot = insertBST(stdRoot, stdTstr[i]);
    }
    char b1[11];
    char b2[11];
    memset(b1, 0, sizeof(char)*11);
    memset(b2, 0, sizeof(char)*11);
    preOrder(stdRoot, b1);
    // printf("\n");
    inOrder(stdRoot, b2);
    // printf("\n");
    // printf("\n");
    while (N-- > 0) {
        string tmpStr;
        getline(cin, tmpStr);
        treeNode * tmpRoot;
        tmpRoot = NULL;
        for (int i=0; i<tmpStr.size(); i++){
            tmpRoot = insertBST(tmpRoot, tmpStr[i]);
        }
        char a1[11];
        char a2[11];
        memset(a1, 0, sizeof(char)*11);
        memset(a2, 0, sizeof(char)*11);
        preOrder(tmpRoot, a1);
        // printf("\n");
        inOrder(tmpRoot, a2);
        // printf("\n");
        // printf("%s\n", a1);
        // printf("%s\n", a2);

        if (!strcmp(a1, b1) && !strcmp(a2, b2)) printf("YES\n");
        else printf("NO\n");
    }

    //debug
    // char a[11];
    // preOrder(stdRoot, a);
    return 0;
}