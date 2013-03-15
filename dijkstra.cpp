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

int next(bool mst_set[], int dist[])
{
	int near = INT_MAX, near_ind = -1;
	for(int i=0;i<V;i++)
		if(mst_set[i] == false && dist[i] < near)
			{ near_ind = i; near = dist[i];}
	return near_ind;
}

void dijkstra(int graph[V][V], int source)
{
	int dist[V];
	bool mst_set[V];
	for(int i=0;i<V;i++)
	{ dist[i] = INT_MAX; mst_set[i] = false;}
	dist[source] = 0;
	
	for(int count = 1; count < V-1; count++)
	{
		int u = next(mst_set, dist);
		mst_set[u] = true;
		for(int v=0;v<V;v++)
			if(mst_set[v] == false && graph[u][v] && dist[v] > dist[u] + graph[u][v])
				dist[v] = dist[u] + graph[u][v];
	}
	
	for(int i=0;i<V;i++)
		cout<<i<<" "<<dist[i]<<endl;
}

// Dijkstra does not work for Graphs of negative edges
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	/* Let us create the example graph discussed above */
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
 
    dijkstra(graph, 0);
	
    system("pause");
}

