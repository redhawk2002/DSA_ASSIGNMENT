#include<bits/stdc++.h>
using namespace std;
struct BinaryNode{
    char data;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(char data){
        this->data = data;
        left = right = NULL;
    }
};
//Function to print pre-order of binary tree
void preorder(BinaryNode* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
//Function to print in-order of binary tree
void inorder(BinaryNode* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
//Function to print post-order of binary tree
void postorder(BinaryNode* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
//Function to construct binary tree from it's preorder and inorder traversal
BinaryNode* buildTree(char in[], char pre[], int start, int end, unordered_map<char, int>& m, int& index) {
    if(start>end){
        return NULL;
    }
    
    char current = pre[index++];
    BinaryNode* p = new BinaryNode(current);
    int inFind = m[current];
    p->left = buildTree(in, pre, start, inFind-1, m, index);
    p->right = buildTree(in, pre, inFind+1, end, m, index);
    return p;
}
int main(){
    int n;
    cout << "Enter the number of characters into the traversal: "; cin>>n;
    cout << endl;
    char in[n],pre[n];
    cout << "Enter inorder traversal for the tree: ";
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    cout << "Enter preorder traversal for the tree: ";
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    unordered_map<char,int> m;
    for(int i=0;i<n;i++){
        m[in[i]] = i;
    }
    int start = 0;
    int end = n-1;
    int index = 0;
    BinaryNode* root = buildTree(in, pre, start, end, m, index);
    cout<<"Pre-order traversal: ";
    preorder(root);
    cout << endl;
    cout<<"In-order traversal: ";
    inorder(root);
    cout << endl;
    cout<<"Post-order traversal: ";
    postorder(root);
    cout << endl;
}





