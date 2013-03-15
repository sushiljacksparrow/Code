#include<iostream>

using namespace std;

struct node
{
	int element;
	node *right, *left;
};

node NthElement(node *root, int n)
{
	static node nth = NULL;
	static int a;
	if(nth==NULL)
	{
		nth = NthElement(root->left, n);
		a++;
		return root;
		nth = NthElement(root->right, n);
	} else
	{
		return nth;
	}
}

int main()
{
	system("pause");
}