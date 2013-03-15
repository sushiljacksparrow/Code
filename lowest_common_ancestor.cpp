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

int count_matches(node *root, node *p, node *q)
{
	if(root == NULL)
		return 0;
	int matches = count_matches(root->left, p, q) + count_matches(root->right, p, q);
	if(root == p || root == q)
		matches++;
	return matches;
}

node *lowest_common_ancestor(node *root, node *p, node *q)
{
	if(root == NULL)
		return NULL;
	if(root == p || root == q)
		return root;
	int total_matches = count_matches(root->left, p, q);
	if(total_matches == 1)
		return root;
	else if(total_matches == 2)
		return lowest_common_ancestor(root->left, p, q);
	else
		return lowest_common_ancestor(root->right, p, q);
}

node *newNode(int d)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = d;
	temp->left  = NULL;
	temp->right = NULL;
	return temp;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	node *root = newNode(3);
	root->left = newNode(5);
	root->left->left = newNode(6);
	root->left->right = newNode(2);
	root->left->right->left = newNode(7);
	root->left->right->right = newNode(4);
	root->right = newNode(1);
	root->right->left = newNode(0);
	root->right->right = newNode(8);
	
	node *lca = lowest_common_ancestor(root, root->left->right->right, root->left->left);
	cout<<lca->data<<endl;
	

    system("pause");
}

