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

# define V 5

int minKey(int key[], bool mst_set[])
{
	int min = INT_MAX, min_index = -1;
	for(int i=0;i<V;i++)
	{
		if(mst_set[i] == false && key[i] < min)
		{ min = key[i]; min_index = i;}
	}
	return min_index;
}

void printMST(int parent[], int n, int graph[V][V])
{
	printf("Edge    Weight\n");
	for(int i=1;i<n;i++)
		printf("%d - %d %d\n", parent[i], i, graph[i][parent[i]]);
}

int primMST(int graph[][5])
{
	int parent[V];
	int key[V];
	bool mst_set[V];
	
	for(int i=0;i<V;i++)
		mst_set[i] = false, key[i] = INT_MAX;
		
	key[0] = 0;
	parent[0] = -1;
	
	for(int count=0;count<V-1;count++)
	{
		int u = minKey(key, mst_set);
		mst_set[u] = true;
		
		for(int v=0;v<V;v++)
		{
			if(graph[u][v] && mst_set[v] == false && key[v] > graph[u][v])
			{	key[v] = graph[u][v]; parent[v] = u;}
		}
	}
	
	printMST(parent, V, graph);			
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	/* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
 
    // Print the solution
    primMST(graph);	

    system("pause");
}

