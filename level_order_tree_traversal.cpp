#include <iostream>
#include <queue>

using namespace std;

struct node
{
	node *left, *right;
	int data;
};

void levelOrderTraversal(node *root)
{
	node *temp = root;
	queue<node*>Q;
	int currentLevel = 1, nextLevel = 0;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		if(temp->left != NULL)
		{
			Q.push(temp->left);
			nextLevel++;
		}
		if(temp->right != NULL)
		{
			Q.push(temp->right);
			nextLevel++;
		}
		temp = Q.front();
		Q.pop();
		currentLevel--;
		if(currentLevel==0)
		{
			cout<<endl;
			currentLevel = nextLevel;
			nextLevel = 0;
		}
	}
}

node *newNode(int d)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = d;
	return temp;
}

int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(7);
	root->right->right = newNode(8);
	
	levelOrderTraversal(root);
	cout<<endl;
	system("pause");
}
