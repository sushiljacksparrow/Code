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

node *newNode(int d)
{
	node *root = (node*)malloc(sizeof(node));
	root->left = root->right = NULL; root->data = d;
	return root;
}

bool isMember(node *root, int d)
{
	if(root == NULL)
		return false;
	if(root->data == d)
		return true;
	if(root->data < d)
		return isMember(root->right, d);
	else
		return isMember(root->left, d);
}

void insert(node * &root, int d)
{
	if(root == NULL)
		root = newNode(d);
	else
	{
		if(root->data < d)
			insert(root->right, d);
		else
			insert(root->left, d);
	}
}

int delete_min(node *root)
{
	if(root->left == NULL)
	{
		int t = root->data;
		root = root->right;
	} else
	{
		int t= delete_min(root->left);
	}
}

void deletes(node *root, int d)
{
	if(root == NULL)
		return;
	if(root->data < d)
		deletes(root->right, d);
	else if(root->data > d)
		deletes(root->left, d);
	else
	{
		if(root->left == NULL && root->right == NULL)
			root = NULL;
		else if(root->left == NULL)
			root = root->right;
		else if(root->right == NULL)
			root = root->left;
		else
		{
			root->data = delete_min(root);
		}
	}
}

void inorder(node *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	node *root = newNode(3);
	root->left = newNode(2);
	root->left->left = newNode(1);
	root->right = newNode(4);
	inorder(root);
	cout<<endl;
	insert(root, 5);
	insert(root, -1);
	inorder(root);
	cout<<endl;
	deletes(root, 5);
	inorder(root);
    system("pause");
}

