#include<iostream>
using namespace std;

struct node
{
	node *left, *right;
	int data;
};

node *newNode(int d)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = d;
	return temp;
}

// basically inorder traversal
void printRangeBST(node *root, int min, int max)
{
	//cout<<root->data<<endl;
	if(root == NULL)
		return;
	if(root->data > min)
		printRangeBST(root->left, min, max);
	if(root->data >=min && root->data <= max)
		cout<<root->data<<" ";
	if(root->data < max)
		printRangeBST(root->right, min, max);
}

int main()
{
	//cout<<"hello world\n";
	
	node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	
	printRangeBST(root, 10, 25);
	
	return 0;
}
