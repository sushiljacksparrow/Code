#include<iostream>
#include<vector>
#include<algorithm>


#define MAXV 26


using namespace std;

int adj[MAXV][MAXV];
int in[MAXV], out[MAXV], visited[MAXV];
bool registered[MAXV];

void graph_init()
{
    // int i, j;

    // for(i=0; i<MAXV; i++) {
        // in[i] = out[i] = 0;
        // registered[i] = 0;
    // }
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(registered, 0, sizeof(registered));
		memset(adj, 0, sizeof(adj));
}

void insert_edge(int v, int w)
{
    adj[v][w]++;
    in[w]++;
    out[v]++;
    registered[v] = registered[w] = 1;
}


void graph_dfs(int me)
{
    int i;

    for(i=0; i<MAXV; i++) {
        if((adj[me][i] > 0 || adj[i][me] > 0) && !visited[i]) {
            visited[i] = 1;
            graph_dfs(i);
        }
    }
}


int solve()
{
    int i, violations;

    /* o grafo e' conexo? */
    for(i=0; i<MAXV; i++)
        visited[i] = 0;
    for(i=0; i<MAXV; i++) {
        if(registered[i]) {
            visited[i] = 1;
            graph_dfs(i);
            break;
        }
    }
    for(i=0; i<MAXV; i++) {
        if(registered[i] && !visited[i])
            return 0;
    }

    /* comparando in-degrees x out-degrees */
    violations = 0;
    for(i=0; i<MAXV; i++) {
        if(abs(in[i]-out[i]) == 1)
            violations++;
        else if(abs(in[i]-out[i]) > 1)
            return 0;
    }

    /* resposta final... */
    return (violations == 0 || violations == 2);
}
int main()
{
	
	int test, n;
	char word[1024];
	scanf("%d", &test);
	while(test--)
	{
		graph_init();
		scanf("%d", &n);
		for(int i=0;i<n;i++)
		{
			scanf("%s", &word);
			insert_edge(word[0]-'a', word[strlen(word)-1]-'a');
		}
		
		printf("%s\n", solve() ? "Ordering is possible." : "The door cannot be opened.");
	}
	system("pause");
}
	
