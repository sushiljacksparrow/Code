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

node *newnode(int data)
{
	node *root = (node*)malloc(sizeof(node));
	root->data = data;
}

// using BFS for graph traversal
node *clone_graph(node *root)
{
	if(root==NULL)
		return NULL;
	map<node*, node*> visited;
	node *clone = newnode(root->data);
	visited[root]=clone;
	queue<node*>Q;
	Q.push(root);
	while(!Q.empty())
	{
		node *temp = Q.front();
		Q.pop();
		int n = temp->neighbour.size();
		for(int i=0;i<n;i++)
		{
			node *t1 = temp->neighbour[i];
			if(visited.find(t1)==visited.end())
			{
				node *t2 = newnode(t1->data);
				node *temp2 = visited[temp];
				temp2->neighbour.push_back(t2);
				visited[t1]=t2;
				Q.push(t1);
			} else
			{
				node *temp2 = visited[temp];
				temp2->neighbour.push_back(visited[t1]);
			}
		}
	}
	
	return clone;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

