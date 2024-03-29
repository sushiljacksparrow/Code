#include <iostream>

using namespace std;

struct node
{
	node *left, *right;
	int data;
};

node *newNode(int d)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = d;
	return temp;
}

int height(node *root)
{
	if(root == NULL)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

int diameter(node *root)
{
	if(root == NULL)
		return 0;
	int lh = height(root->left);
	int rh = height(root->right);
	
	int ld = diameter(root->left);
	int rd = diameter(root->right);
	
	return max(1+lh+rh, max(ld, rd));
}


int main()
{
	struct node *root = newNode(1);
	root->left        = newNode(2);
  	root->right       = newNode(3);
  	root->left->left  = newNode(4);
  	root->left->right = newNode(5);
 
  	printf("Diameter of the given binary tree is %d\n", diameter(root));
 
  	getchar();
	return 0;
}
