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

int height(node *root)
{
	if(root==null)
		return 0;
	int lh=height(root->left);
	int rh=height(root->right);
	
	return max(lh,rh)+1;
}

int diameter(node *root)
{
	if(root==null)
		return 0;
		
	int lh = height(root->left);
	int rh = height(root->right);
	
	int ldi = diameter(root->left);
	int rdi = diameter(root->right);
	
	return (1+lh+rh, max(ldi, rdi));
}


void inorder_traversal(node *root)
{
	node *current = root;
	stack<node*>S;
	while(1)
	{
		if(current!=NULL)
		{
			S.push(current);
			current=current->left;
		} else
		{
			if(!S.empty())
			{
				node *temp = S.top();
				S.pop();
				cout<<temp->value<<" ";
				temp=temp->right;
				S.push(temp);
			} else
			{
				break;
			}
		}
	}
}


node *construct(int *inorder, int *preorder, int instart, int inend)
{
	if(instart>inend)
		return null;
		
	int static preindex=0;
	int ind;
	
	node * temp = (node *)malloc(sizeof(node*));
	temp->value=preorder[preindex];
	
	for(i=instart;i<inend;i++)
		if(inorder[i]==preorder[preindex])
			break;
	preindex++;
	temp->left=construct(inoder, preorder, instart, i-1);
	temp->right=construct(inder, preorder, i+1, inend);
	
	return temp;
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

