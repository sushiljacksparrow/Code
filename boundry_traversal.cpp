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
	node *root = (node*)malloc(sizeof(node));
	root->left = root->right = NULL;
	root->data = d;
	return root;
}

void left_traversal(node *root)
{
	if(root)
	{
		if(root->left)
		{
			cout<<root->data<<" ";
			left_traversal(root->left);
		} else if(root->right)
		{
			cout<<root->data<<" ";
			left_traversal(root->right);
		}
	}
}

void right_traversal(node *root)
{
	if(root)
	{
		if(root->right)
		{
			cout<<root->data<<" ";
			right_traversal(root->right);
		} else if(root->left)
		{
			cout<<root->data<<" ";
			right_traversal(root->left);
		}
	}
}

void leaves_traversal(node *root)
{
	if(root)
	{
		leaves_traversal(root->left);
		if(root->left == NULL&& root->right == NULL)
			cout<<root->data<<" ";
		leaves_traversal(root->right);
	}
}

void traversal(node *root)
{
	if(root == NULL)
		return;
	cout<<root->data<<" ";
	left_traversal(root->left);
	leaves_traversal(root->left);
	leaves_traversal(root->right);
	right_traversal(root->right);
}
	
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
    traversal( root );

    system("pause");
}

