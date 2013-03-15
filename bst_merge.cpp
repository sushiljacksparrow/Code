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

node *newNode(int d)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->left = NULL; temp->right = NULL; temp->data = d;
	return temp;
}

void iterative_inorder(node *root)
{
	if(root == NULL)
		return;
	stack<node *>S;
	while(true)
	{
		if(root)
		{
			S.push(root);
			root = root->left;
		} else
		{
			if(S.empty())
				break;
		
			root = S.top();
			S.pop();
			cout<<root->data<<" ";
			root = root->right;
		}
	}
}

void merge(node *root1, node *root2)
{	
	if(root1== NULL && root2==NULL)
		return;
	if(root1==NULL)
		{iterative_inorder(root2); return;}
	if(root2==NULL)
		{iterative_inorder(root1); return;}
	
		
	stack<node*>S1, S2;
	while(true)
	{
		if(root1 || root2)
		{
			if(root1)
			{
				S1.push(root1);
				root1 = root1->left;
			}
			if(root2)
			{
				S2.push(root2);
				root2 = root2->left;
			}
		} else
		{
			if(S1.empty())
			{
				while(!S2.empty())
				{
					root2 = S2.top();
					root2->left = NULL;
					iterative_inorder(root2);
				}
				return;
			} else if(S2.empty())
			{
				while(!S1.empty())
				{
					root1 = S1.top();
					root1->left = NULL;
					iterative_inorder(root1);
				}
				return;
			}
			
			root1 = S1.top();
			S1.pop();
			root2 = S2.top();
			S2.pop();
			
			if(root1->data < root2->data)
			{
				cout<<root1->data<<" ";
				root1 = root1->right;
				S2.push(root2);
				root2 = NULL;
			} else
			{
				cout<<root2->data<<" ";
				root2 = root2->right;
				S1.push(root1);
				root1 = NULL;
			}
		}
	}
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	node *root1 = newNode(1);
	root1->left = newNode(2);
	root1->right = newNode(3);
	root1->left->left = newNode(4);
	root1->left->right = newNode(5);
	
	//iterative_inorder(root1);
	
	node *root2 = newNode(5);
	root2->left = newNode(4);
	root2->right = newNode(6);
	
	merge(root1, root2);

    system("pause");
}

