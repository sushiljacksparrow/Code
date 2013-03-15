#include <iostream>
#include <stack>
#include <algorithm>

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

int kthSmallest(node *root, int k)
{
	if(root == NULL)
		return -1;
	node *current = root;
	stack<node *> S;
	while(true)
	{
		if(current)
		{
			S.push(current);
			current = current->left;
		} else
		{
			if(!S.empty())
			{
				current = S.top();
				S.pop();
				if(k==1)
					return current->data;
				cout<<current->data<<" ";
				k--;
				current = current->right;
			} else
			{
				break;
			}
		}
	}
	return -1;
}

int main()
{
	node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	
	int ans = kthSmallest(root, 5);
	cout<<"\nAns "<<ans<<endl;
	//cout<< (ans == -1 ? "Not found" : ans)<<endl;
	return 0;
}
