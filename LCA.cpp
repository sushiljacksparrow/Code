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

// LCA of a BST
node *LCA_BST(node *r, node *r1, node *r2)
{
	if(r==NULL || r1 == NULL || r2==NULL)
		return NULL;
	if(max(r1->data, r2->data) < r->data)
		return LCA_BST(r->left, r1, r2);
	else if(min(r1->data, r2->data) > r->data)
		return LCA_BST(r->right, r1, r2);
	else
		return r;
}

int count(node *root, node *p, node *q)
{
	if(root==NULL)
		return 0;
	int match = count(root->left, p, q) + count(root->right, p, q);
	if(root == p || root==q)
		return 1+match;
	else
		return match;
}
	
// LCA of a binary stree

node *LCA(node *r, node *p, node *q)
{
	if(r==NULL || p==NULL || q==NULL)
		return NULL;
	if(r==p || r==q)
		return r;
	
	int totalMatch = count(r->left, p, q);
	if(totalMatch==1)
		return r;
	if(totalMatch==2)
		return LCA(r->left, p, q);
	else
		return LCA(r->right, p, q);
}

// bottomo up approach

node *LCA_b(node *root, node *p, node *q)
{
	if(root==NULL)
		return root;
	if(root==p || root==q)
		return root;
	node *L = LCA_b(root->left, p, q);
	node *R = LCA_b(root->right, p, q);
	if(L && R)
		return root;
	return L ? L : R;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

