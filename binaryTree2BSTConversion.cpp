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
	node *right, *left;
	int data;
};

node *newNode(int d)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->left = temp->right = NULL;
	temp->data = d;
	return temp;
}

int size(node *root)
{
	if(root == NULL)
		return 0;
	else
		return 1 + size(root->left) + size(root->right);
}
	
void store_in_array(node *root, int arr[], int *index)
{
	if(root)
	{
		store_in_array(root->left, arr, index);
		arr[*index] = root->data;
		(*index)++;
		store_in_array(root->right, arr, index+1);
	}
}

void array_to_BST(int arr[], node *root, int *index)
{
	if(root)
	{
		array_to_BST(arr, root->left, index);
		root->data = arr[*index];
		(*index)++;
		array_to_BST(arr, root->right, index);
	}
}

void BT2BST(node *root)
{
	int n = size(root);
	int arr[n];
	int i = 0;
	store_in_array(root, arr, &i);		
	sort(arr, arr+n);
	i = 0;
	array_to_BST(arr, root, &i);
	delete[] arr;
}

void inorder_traversal(node *root)
{
	if(root == NULL)
		return;
	node *current = root;
	while(current)
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
			if(pre->right == current)
			{
				pre->right = NULL;
				cout<<current->data<<" ";
				current = current->right;
			} else
			{
				pre->right = current;
				//cout<<current->data<<" ";
				current = current->left;
			}
		}
	}
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
	BT2BST(root);
	inorder_traversal(root);
	

    system("pause");
}

