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

// bottom up approach, works for a binary tree
node *LCA(node *root, node *p, node *q)
{
	if(root == NULL)
		return root;
	if(root==p || root==q)
		return root;
	node *L = LCA(root->left, p, q);
	node *R = LCA(root->right, p, q);
	
	if(L && R)
		return root;
	else if(L!=NULL)
		return L;
	else
		return R;
}

// works for a BST
node *LCA_binary(node *root, node *p, node *q)
{
	if(root == NULL)
		return NULL;
	if(root->data > p->data && root->data > q->data)
		return LCA_binary(root->left, p, q);
	else if(root->data < p->data && root->data < q->data)
		return LCA_binary(root->right, p, q);
	else
		return root;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

