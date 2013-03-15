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
	int data;
	node *left, *right;
};


node *newnode(int data)
{
	node *n = (node*)malloc(sizeof(node));
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void inorder(node *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	inorder(root->left);
	inorder(root->right);
}

void iterative_inorder(node *root)
{
	if(root==NULL)
		return;
	stack<node*>S;
	S.push(root);
	
	
	while(!S.empty())
	{
		node *temp = S.top();
		S.pop();
		cout<<temp->data<<" ";
		if(temp->right!=NULL)
			S.push(temp->right);
		if(temp->left!=NULL)
			S.push(temp->left);
	}
}

void iterative_post_order(node *root)
{
	if(root == NULL)
		return;
	stack<node*>S;
	S.push(root);
	node  *prev=NULL;
	
	while(!S.empty())
	{
		node *current = S.top();
		
		if(prev == NULL || prev->left == current || prev->right == current)
		{
			if(current->left != NULL)
				S.push(current->left);
			else if(current->right != NULL)
				S.push(current->right);
			else
			{
				cout<<current->data<<" ";
				S.pop();
			}
		} else if(current->left == prev)
		{
			if(current->right != NULL)
			{
				S.push(current->right);
			} else
			{
				cout<<current->data<<" ";
				S.pop();
			}
		} else if(current->right == prev)
		{
			
				cout<<current->data<<" ";
				S.pop();
		}
				prev = current;
		
	}
}

void level_order(node *root)
{
	if(root == NULL)
		return;
	queue<node*>currentQ;
	queue<node*>nextQ;
	currentQ.push(root);
	
	while(!currentQ.empty())
	{
		node *current = currentQ.front();
		currentQ.pop();
		if(current)
		{
			cout<<current->data<<" ";
			nextQ.push(current->left);
			nextQ.push(current->right);
		}
		if(currentQ.empty())
		{
			cout<<endl;
			swap(currentQ, nextQ);
		}
	}
}


void level_order_zigzag(node *root)
{
	if(root == NULL)
		return;
	stack<node*>currentS;
	stack<node*> nextS;
	currentS.push(root);
	bool lefttoright = false;
	while(!currentS.empty())
	{
		node *current = currentS.top();
		currentS.pop();
		if(current)
		{
			cout<<current->data<<" ";
			
			if(lefttoright)
			{
				nextS.push(current->left);
				nextS.push(current->right);
			} else
			{
				nextS.push(current->right);
				nextS.push(current->left);
			}
		} 
		
		if(currentS.empty())
		{
			cout<<endl;
			lefttoright = !lefttoright;
			swap(currentS, nextS);
		}
	}
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	node *root = newnode(1);
	root->left        = newnode(2);
	root->right       = newnode(3);
	root->left->left  = newnode(4);
  	root->left->right = newnode(5); 
//  	cout<<"recursive\n";
	inorder(root);
//	cout<<"\niterative\n";
//	iterative_inorder(root);
//	
//	cout<<"\n iterative post order \n";
//	iterative_post_order(root);
	cout<<"\n level order\n";
	level_order(root);
	cout<<"nzig\n";
	level_order_zigzag(root);
    system("pause");
}

