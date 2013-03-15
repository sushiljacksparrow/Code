#include <iostream>

using namespace std;

struct edge
{
	int src, dest;
};

struct graph
{
	int v, e;
	edge * edges;
};


graph *create_graph(int v, int e)
{
	graph* g = (struct graph*) malloc( sizeof(struct graph) );
    g->v = v;
    g->e = e;
 
    g->edges = (struct edge*) malloc( g->e * sizeof( struct edge ) );
 
    return g;
}

int find(int *parent, int i)
{
//	cout<<"---"<<v<<" ";
	if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int *parent, int x, int y)
{
	int xset = find(parent, x);
	int yset = find(parent, y);
	parent[xset] = yset;
}



bool is_cycle(graph *g)
{
// Allocate memory for creating V subsets
    int *parent = (int*) malloc( g->v * sizeof(int) );
 
    // Initialize all subsets as single element sets
    memset(parent, -1, sizeof(int) * g->v);
 
    // Iterate through all edges of graph, find subset of both
    // vertices of every edge, if both subsets are same, then there is
    // cycle in graph.
    for(int i = 0; i < g->e; ++i)
    {
        int x = find(parent, g->edges[i].src);
        int y = find(parent, g->edges[i].dest);
 
        if (x == y)
        {
			cout<<x<<" "<<find(parent, g->edges[i].src)<<endl;
			cout<<y<<" "<<find(parent, g->edges[i].dest)<<endl;
            return 1;
		}
 
        Union(parent, x, y);
    }
    return 0;
}
	
int main()
{
	graph *g = create_graph(3,3);
	g->edges[0].src = 0;
	g->edges[0].dest = 1;
	
	g->edges[1].src = 1;
	g->edges[1].dest = 2;
	
	//g->edges[2].src = 0;
	//g->edges[2].dest = 2;
	
//	cout<<"1";
	if(is_cycle(g))
		printf("Graph contains cycle\n");
	else
		printf("Graph does not contain cycle\n");
	
	system("pause");
}


