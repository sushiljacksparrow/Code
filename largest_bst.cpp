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

int ans = INT_MIN;


struct node
{
	node *left, *right;
	int data;
};

node *bst_root;

node *newNode(int d)
{
	node *root = (node*)malloc(sizeof(node));
	root->left = root->right = NULL;
	root->data = d;
	return root;
}

bool isBST(node *root, int mini, int maxi)
{
	if(root == NULL)
		return true;
	else if(root->data < mini || root->data > maxi)
		return false;
	else
		return isBST(root->left, mini, root->data) && isBST(root->right, root->data, maxi);
}

int count_nodes(node *root)
{
	if(root == NULL)
		return 0;
	else if(root->left == NULL && root->right == NULL)
		return 1;
	else
		return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int largest_BST(node *root)
{
	if(root == NULL)
		return 0;
	if(isBST(root, INT_MIN, INT_MAX))
	{
		if(count_nodes(root) > ans)
			bst_root = root;
		return count_nodes(root);
	}
	else 
		return max(largest_BST(root->left), largest_BST(root->right));
	
}
					 
void inorder_bst(node *root)
{
	if(root == NULL)
		return ;
	inorder_bst(root->left);
	cout<<root->data<<" ";
	inorder_bst(root->right);
}		
					
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	node *root = newNode(10);
	root->left = newNode(5);
	root->left->left = newNode(1);
	root->left->right = newNode(8);
	root->right = newNode(15);
	root->right->right = newNode(7);
	root->left->left->left = newNode(14);
	int x = largest_BST(root);
	cout<<x<<endl;
	inorder_bst(bst_root);
    system("pause");
}

