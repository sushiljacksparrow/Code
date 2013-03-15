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

#define V 9

// bellman ford works for negative cycles as well
void bellman_ford(int graph[V][V], int src)
{
	int dist[V];
	for(int i=0;i<V;i++)
		dist[i] = INT_MAX;
	dist[src] = 0;
	
	for(int i=0;i<V-1;i++)
	{
		for(int j=0;j<V;j++)
		{
			for(int k=0;k<V;k++)
			{
				if(graph[j][k] && (dist[k] > dist[j] + graph[j][k]))
					dist[k] = dist[j] + graph[j][k];
			}
		}
	}
	cout<<"hello world\n";
	// check for negative cycles;
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(dist[j] > dist[i] + graph[i][j])
			{	cout<<"negative cycle\n"; return;}
		}
	}
	
	for(int i=0;i<V;i++)
		cout<<i<<" "<<dist[i]<<endl;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	 int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {0, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
 
    bellman_ford(graph, 0);
    system("pause");
}

