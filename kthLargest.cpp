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
	root->data = d; root->left = root->right = NULL;
	root->data = d;
	return root;
}

node* findKth(node *root, int k)
{
	if(root == NULL)
		return NULL;
	node *current = root;
	int count = 0;
	node *ret = NULL;
	while(current != NULL)
	{
		if(current->left  == NULL)
		{
			count++;
//			cout<<current->data<<" ";
			if(count == k)
			{ 
				ret = current;
				break;
			}
			current = current->right;
		} else
		{
			node *prev = current->left;
			while(prev->right != NULL && prev->right != current)
				prev = prev->right;
			if(prev->right == NULL)
			{
				prev->right = current;
				current = current->left;
			} else
			{
				prev->right = NULL;
				count++;
//				cout<<current->data<<" ";
				if(count == k)
				{
					ret = current;
					break;
				}
				current = current->right;
			}
		}
	}
	return ret;
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	node *root = newNode(4);
	root->right = newNode(5);
	root->left = newNode(2);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	int k = 4;
	node *kth = findKth(root, 3);
	if(kth == NULL)
		cout<<"NULL\n";
	else
		cout<<kth->data<<endl;
    system("pause");
}

