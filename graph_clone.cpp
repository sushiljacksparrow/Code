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
	vector<node*>neighbour;
};


node *newNode(int d)
{
	node *root = (node *)malloc(sizeof(node));
	root->data = d;
}

node *graph_clone(node *root)
{
	if(root==NULL)
		return NULL;
	map<node *, node *> mapping;
	node *root_clone = newNode(root->data);
	mapping[root] = root_clone;
	queue<node *>Q;
	Q.push(root);
	while(!Q.empty())
	{
		node *temp = Q.front();
		Q.pop();
		int n = temp->neighbour.size();
		for(int i=0;i<n;i++)
		{
			node *nb = temp->neighbour[i];
			if(mapping.find(nb) == mapping.end())
			{
				node *tt = newNode(nb->data);
				mapping[nb]->neighbour.push_back(tt);
				mapping[nb] = tt;
				Q.push(nb);
			} else
			{
				mapping[nb]->neighbour.push_back(mapping[nb]);
			}
		}
	}
	return root_clone;
}
			
			
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	node *node1 = newNode(1);
	node *node2 = newNode(2);
	node *node3 = newNode(3);
	node1->neighbour.push_back(node2);
	node2->neighbour.push_back(node3);
	
	
    system("pause");
}

