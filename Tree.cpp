#include<iostream>
#include<stack.h>

struct node
{
	int data;
	node *left, *right;
};

node *newNode(int data)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
}



void iterative_preorder(node *root)
{
	if(root == NULL)
		return;
	stack<node *>S;
	S.push(root);
	while(!S.empty())
	{
		node *temp = S.top(); S.pop();
		cout<<temp->data<<" ";
		if(temp->right!=NULL)
			S.push(temp->right);
		if(temp->left!=NULL)
			S.push(temp->left);
	}
}

void iterative_inorder(node *root)
{
	node *current = root;
	stack<node *>S;
	// S.push(current);
	while(true)
	{
		cout<<current->data<<endl;
		if(current!=NULL)
		{
			// current = current->left;
			S.push(current);
			current = current->left;
		} else
		{
			if(S.empty() == true)
				break;
			else
			{
				current = S.top(); S.pop();
				if(current!=NULL)
					current = current->right;
			}
		}
	}
}

node *construct_tree(int pre[], int pres, pree, int in[], int ins)
{
	if(pree<pres)
		return NULL;
	node *temp = newnode(in[ins]);
	int index = pres;
	for(int i=pres;i<=pree;i++)
		if(pre[i]==in[ins])
			{index = i; break}
	temp->left = construct_tree(pre, pres, index-1, in, ins+1);
	temp->right = construct_tree(pre, index+1, pree, in, ins+1);
	return temp;
}


int main()
{
	struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  iterative_inorder(root);
	system("pause");
}
