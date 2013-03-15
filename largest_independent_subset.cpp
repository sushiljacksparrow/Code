/*Sushil Kumar Singh */
//http://www.geeksforgeeks.org/largest-independent-set-problem/
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


struct bnode
{
	bnode *left, *right;
	int data;
	int liss;
};

struct nnode
{
	int data;
	int liss;
	vector<nnode*> child;
};




bnode* new_bnode(int d)
{
	bnode *temp = (bnode*)malloc(sizeof(bnode));
	temp->left = temp->right = NULL;
	temp->data = d;
	temp->liss = 0;
	return temp;
}

nnode *new_nnode(int d)
{
	nnode *temp = (nnode*)malloc(sizeof(nnode));
	temp->data = d;
	temp->liss = 0;
	return temp;
}

// binary tree LISS with modification of tree
int BLISS(bnode *root)
{
	if(root == NULL)
		return 0;
	if(root->liss)
		return root->liss;
	if(root->left == NULL && root->right == NULL)
		return (root->liss = 1);
	int excl = BLISS(root->left) + BLISS(root->right);
	int incl = 1;
	if(root->left)
		incl += BLISS(root->left->left) + BLISS(root->left->right);
	if(root->right)
		incl += BLISS(root->right->left) + BLISS(root->right->right);
		
	root->liss = max(incl, excl);
	return root->liss;
}

// n-ary tree LISS with modification of tree
int NLISS(nnode *root)
{
	if(root == NULL)
		return 0;
	if(root->liss)
		return root->liss;
	if(root->child.size()==0)
		return (root->liss = 1);
	
	int excl = 0;
	for(int i=0;i<root->child.size();i++)
		excl += NLISS(root->child[i]);
	
	int incl = 1;
	for(int i=0;i<root->child.size();i++)
	{
		nnode *ch = root->child[i];
		for(int j=0;j<ch->child.size();j++)
		{
			incl+=NLISS(ch->child[j]);
		}
	}
	return (root->liss = max(excl, incl));
}


void inorder(bnode *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" "<<root->liss<<endl;
	inorder(root->right);
}

bnode* construct_btree()
{
	bnode *root = new_bnode(10);
	root->left = new_bnode(20);
	root->left->left = new_bnode(40);
	root->left->right = new_bnode(50);
	root->left->right->left = new_bnode(70);
	root->left->right->right = new_bnode(80);
	root->right = new_bnode(30);
	root->right->right = new_bnode(60);
	return root;
}



//  Longest independent subset without modification in O(n) time
map<nnode*, int>mapp;
int nliss_without_modification(nnode *root)
{
	if(root == NULL)
		return 0;
	if(root->child.size()==0)
	{
		mapp[root] = 1;
		return mapp[root];
	}
	if(mapp[root])
		return mapp[root];
	int excl = 0;
	for(int i=0;i<root->child.size();i++)
		excl += nliss_without_modification(root->child[i]);
	int incl = 1;
	for(int i=0;i<root->child.size();i++)
	{
		nnode *temp = root->child[i];
		for(int j=0;j<temp->child.size();j++)
			incl += nliss_without_modification(temp->child[j]);
	}
	return (mapp[root] = max(incl, excl));
}

int max_size = 0;

int nliss_without_modification_with_storage(nnode *root, set<nnode*>s)
{
	
}
		
// Longest independent subset for binary tree without modification in O(n) time

map<bnode*, int> bmapp;
int bliss_without_modification(bnode* root)
{
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return bmapp[root] = 1;
	if(bmapp[root])
		return bmapp[root];
	int excl = bliss_without_modification(root->left) + bliss_without_modification(root->right);
	int incl = 1;
	if(root->left)
		incl += bliss_without_modification(root->left->left) + bliss_without_modification(root->left->right);
	if(root->right)
		incl += bliss_without_modification(root->right->left) + bliss_without_modification(root->right->right);
	return bmapp[root] = max(incl, excl);
}



nnode *construct_ntree()
{
	nnode *root10 = new_nnode(10);
	nnode *root20 = new_nnode(20);
	nnode *root30 = new_nnode(30);
	nnode *root40 = new_nnode(40);
	nnode *root50 = new_nnode(50);
	nnode *root60 = new_nnode(60);
	nnode *root70 = new_nnode(70);
	nnode *root80 = new_nnode(80);
	
	root10->child.push_back(root20); root10->child.push_back(root30);
	root20->child.push_back(root40); root20->child.push_back(root50);
	root50->child.push_back(root70); root50->child.push_back(root80);
	root30->child.push_back(root60);
	return root10;
}


	
	
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	bnode *root = construct_btree();
	int ans = bliss_without_modification(root);
	//inorder(root);
	cout<<ans<<endl;

    system("pause");
}

