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
	vector<node*>list;
};

node *bfs_clone(node *root)
{
	if(root==NULL)
		return NULL;
	
	map<node*, node*> mapp;
	queue<node*>Q;
	Q.push(root);
	
	node *clone = (node*)malloc(sizeof(node*));
	mapp[clone]=clone;
	
	while(!Q.empty())
	{
		node *temp = Q.front();
		Q.pop();
		int len = temp->list.size();
		for(int i=0;i<len;i++)
		{
			node *next = temp->list[i];
			if(mapp.find(next) == mapp.end())
			{
				node *clone_next = (node *)malloc(sizeof(node*));
				next->list.push_back(clone_next);
				mapp[clone_next] = clone_next;
				Q.push(clone_next);
			} else
			{
				next->list.push_back(mapp[next]);
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

