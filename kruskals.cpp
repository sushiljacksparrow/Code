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

struct edge
{
	int src, dest, weight;
};

struct graph
{
	int v, e;
	edge *edges;
};


struct subset
{
	int parent, rank;
};

graph *create_graph(int v, int e)
{
	graph *g = (graph*)malloc(sizeof(graph));
	g->v = v;
	g->e = e;
	g->edges = (edge*)malloc(g->e * sizeof(edge));
	return g;
}

int find(subset *subsets, int i)
{
	if(subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

void Union(subset *subsets, int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);
	
	if(subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = subsets[yroot].parent;
	else if(subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = subsets[xroot].parent;
	else
	{
		subsets[xroot].parent = subsets[yroot].parent;
		subsets[yroot].rank++;
	}
}

int myComp(const void *a, const void *b)
{
	edge *e1 = (edge*)a;
	edge *e2 = (edge*)b;
	return e1->weight > e2->weight;
}


void kruskals(graph *g)
{
	qsort(g->edges, g->e, sizeof(g->edges[0]), myComp);
	subset *subsets = (subset*)malloc(g->v * sizeof(subset));
	
	for(int i=0;i<g->v;i++)
	{
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}
	
	int e = g->e;
	int v = g->v;
	int i=0;
	
	edge results[v];
	
	while(e<v-1)
	{
		edge temp_edge = g->edges[i++];
		int x = find(subsets, temp_edge.src);
		int y = find(subsets, temp_edge.dest);
		
		if(x != y)
		{
			results[e++] = temp_edge;
			Union(subsets, x, y);
		}		
	}
	
	for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", results[i].src, results[i].dest,
                                                   results[i].weight);
}
	
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    graph* g = create_graph(V, E);
 
 
    // add edge 0-1
    g->edges[0].src = 0;
    g->edges[0].dest = 1;
    g->edges[0].weight = 10;
 
    // add edge 0-2
    g->edges[1].src = 0;
    g->edges[1].dest = 2;
    g->edges[1].weight = 6;
 
    // add edge 0-3
    g->edges[2].src = 0;
    g->edges[2].dest = 3;
    g->edges[2].weight = 5;
 
    // add edge 1-3
    g->edges[3].src = 1;
    g->edges[3].dest = 3;
    g->edges[3].weight = 15;
 
    // add edge 2-3
    g->edges[4].src = 2;
    g->edges[4].dest = 3;
    g->edges[4].weight = 4;
 

	kruskals(g);
    system("pause");
}

