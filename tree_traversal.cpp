/*Sushil Kumar Singh */
#include <cassert>
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
#include <ext/numeric>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/algorithm>

using namespace std;
using namespace __gnu_cxx;

#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define ii pair<int,int>
#define vs vector<string>
#define all(v) (v).begin(), (v).end()
#define For(i,x) for(int i=0;i<x;i++)

struct node
{
	node *left, *right;
	int data;
};

void iterative_inorder(node *root)
{
	node *current = root;
	while(current != NULL)
	{
		if(current->left == NULL)
		{
			cout<<current->data<<" ";
			current = current->right;
		} else
		{
			node *pre = current->left;
			while(pre->right != NULL && pre->right != current)
				pre = pre->right;
			if(pre->right == NULL)
			{
				pre->right = current;
				current = current->left;
			} else
			{
				pre->right = NULL;
				cout<<current->data<<" ";
				current = current->right;
			}
		}
	}
}

void iterative_preorder(node *root)
{
	node *current = root;
	while(current != NULL)
	{
		if(current->left == NULL)
		{
			cout<<current->data<<" ";
			current = current->right;
		} else
		{
			node *pre = current->left;
			while(pre->right != NULL && pre->right != current)
				pre = pre->right;
			if(pre->right == NULL)
			{
				cout<<current->data<<" ";
				pre->right = current;
				current = current->left;
				
			} else
			{
				pre->right = NULL;
				current = current->right;
			}
		}
	}
}
		

void stack_inorder(node *root)
{
	stack<node*>S;
	node *current = root;
	while(true)
	{
		if(current != NULL)
		{
			S.push(current);
			current = current->left;
		} else
		{
			if(S.empty())
			{
				break;
			}
			current = S.top();
			S.pop();
			cout<<current->data<<" ";
			current = current->right;
		}
	}
}


void stack_preorder(node *root)
{
	if(root == NULL)
		return;
	stack<node*>S;
	S.push(root);
	while(!S.empty())
	{
		node *current = S.top();
		S.pop();
		cout<<current->data<<" ";
		if(current->right != NULL)
			S.push(current->right);
		if(current->left != NULL)
			S.push(current->left);
	}
}

void stack_postorder(node *root)
{
	if(root == NULL)
		return;
	node *current = root;
	stack<node *> S;

	do
	{
		if(current)
		{
			if(current->right)
				S.push(current->right);
			S.push(current);
			current = current->left;
		}
		
		current = S.top();
		S.pop();
		
		if(current->right && current->right == S.top())
		{
			S.pop();
			S.push(current);
			current = current->right;
		} else
		{
			cout<<current->data<<" ";
			current = NULL;
		}
	} while(!S.empty());
}

node *newNode(int d)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = d;
	return temp;
}
				
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	node *root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right = newNode(3);
	//iterative_inorder(root);
//	cout<<endl;
//	stack_inorder(root);
//	cout<<endl;
//	stack_preorder(root);
//	cout<<endl;
//	stack_postorder(root);
//	cout<<endl;
	iterative_preorder(root);
    system("pause");
}

