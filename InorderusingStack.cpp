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
void inorder(node *root)
{
	stack<node *>S;
	node *current=root;
	bool done = false;
	while(!done)
	{
		if(current!=NULL)
		{
			S.push(current);
			current=current->left;
		} else
		{
			if(!S.empty())
			{
				current=S.top();
				cout<<current->data<<" ";
				S.pop();
				current=current->right;
			} else
			{
				done = true;
			}
		}
	}
}	
node *newnode(int d)
{
	node *root=(node *)malloc(sizeof(node*));
	root->left=NULL;
	root->right=NULL;
	root->data=d;
	return root;
}
void treeinsert(node **root, int n)
{
	node *temp=*root;
	if(temp==NULL)
	{
		*root=newnode(n);
	} else
	{
		if(n>=(*root)->data)
			treeinsert(&((*root)->right), n);
		else
			treeinsert(&((*root)->left), n);
	}
}
			
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	node *root=NULL;
	treeinsert(&root, 4);
		treeinsert(&root, 3);
			treeinsert(&root, 1);
				treeinsert(&root, 5);
	inorder(root);
    system("pause");
}

