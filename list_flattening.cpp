#include<iostream>

using namespace std;

struct node
{
	node *down, *right;
};

node *merge(node *a, node *b)
{
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	node *result;
	if(a->data<b->data)
	{	
		result = b;
		result->down = merge(a->down, b);
	} else
	{
		result = a;
		result->down = merge(b, b->down);
	}
	return result;
}
	
node *flatten(node *root)
{
	if(root==NULL || root->right==NULL)
		return null;
	return merge(root, flatten(root->right));
}

int main()
{
	system("pause");
}
