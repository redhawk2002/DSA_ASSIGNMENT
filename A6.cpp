#include<bits/stdc++.h>
using namespace std;

class BinaryNode {
    public:
        char data;
        BinaryNode* left;
        BinaryNode* right;
};

BinaryNode * newNode(char data){
    BinaryNode *BNode = new BinaryNode();
	BNode->data = data;
	BNode->left = NULL;
	BNode->right = NULL;
	return (BNode);
}

int Search(char arr[], int start, int end, int val);


BinaryNode * BuildTree(char InOrder[], char PreOrder[], int iStart, int iEnd) {
    static int preIndex = 0;
    if (iStart > iEnd)
        return NULL;
    BinaryNode * temp = newNode(PreOrder[preIndex++]);
    if (iStart == iEnd)
        return temp;
    int iIndex = Search(InOrder, iStart, iEnd, temp->data);
    temp->left = BuildTree(InOrder, PreOrder, iStart, iIndex - 1);
	temp->right = BuildTree(InOrder, PreOrder, iIndex + 1, iEnd);
	return temp;
}

int Search(char arr[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == val)
            return i;
    }
}

void preorder(BinaryNode *root)
{
	if (root != NULL)
	{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(BinaryNode *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void postorder(BinaryNode *root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}

int main() {
    int len;
	cout << "Enter the number of characters into the traversal: ";
	cin >> len;
	cout << endl;
	char in[len], pre[len];
	cout << "Enter inorder traversal for the tree: ";
	for (int i = 0; i < len; i++)
	{
		cin >> in[i];
	}
	cout << "Enter preorder traversal for the tree: ";
	for (int i = 0; i < len; i++)
	{
		cin >> pre[i];
	}
	BinaryNode * root = BuildTree(in , pre, 0, len - 1);
	cout << "Pre-order traversal: ";
	preorder(root);
	cout << endl;
	cout << "In-order traversal: ";
	inorder(root);
	cout << endl;
	cout << "Post-order traversal: ";
	postorder(root);
	cout << endl;
}
