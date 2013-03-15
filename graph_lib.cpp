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



void path(int start, int end, int parent[])
{
	if((start==end) || (end==-1))
	{
		printf(" %d ", start);
	} else
	{
		path(start, parent[end], parent);
		printf(" %d ", end);
	}
}

void bfs(vector< vector<int> > g, int root)
{
	int vertex = g.size();
	int state[vertex];
	memset(state, 0, sizeof(state));
	int parent[vertex];
	memset(parent, -1, sizeof(parent));
	
	state[root]=1;
	queue<int>Q;
	Q.push(root);
	while(!Q.empty())
	{
		int temp = Q.front();
		Q.pop();
		int len=g[temp].size();
		for(int i=0;i<len;i++)
		{
			if(state[g[len][i]]==0)
			{
				state[g[len][i]]=1;
				parent[g[len][i]]=temp;
				Q.push(g[len][i]);
			}
		}
		state[temp]=2;
	}
	path(0, 3, parent);
}



int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	int n, m, s, e;
	cin>>n>>m;
	vector< vector<int> >g(n);
	for(int i=0;i<m;i++)
	{
		cin>>s>>e;
		g[s].push_back(e);
	}
	bfs(g, 0);	
	
    system("pause");
}

