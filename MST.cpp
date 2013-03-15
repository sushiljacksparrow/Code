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

#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>

#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <set>

#include <stack>
#include <string>
#include <utility>

#include <vector>


using namespace std;


#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define ii pair<int,int>
#define vs vector<string>
#define all(v) (v).begin(), (v).end()
#define For(i,x) for(int i=0;i<x;i++)

struct edge
{
	int s,e,cost;
};

bool compare(edge e1, edge e2)
{
	return e1.cost <= e2.cost;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int n,m;
	scanf("%d %d", &n, &m);
	int st, end, c;
	vector<edge>edges(m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d", &st, &end, &c);
		edges[i].s=st;
		edges[i].e=end;
		edges[i].cost=c;
	}
	
	sort(edges.begin(), edges.end(), compare);
	int color[n+1];
	for(int i=1;i<=n;i++)
		color[i]=i;
	
	int mstCost=0;
	for(int i=0;i<m;i++)
	{
		if(color[edges[i].s]!=color[edges[i].e])
		{
			mstCost+=edges[i].cost;
			int oldColor = color[edges[i].e];
			for(int j=1;j<=n;j++)
			{
				if(color[j]==oldColor)
				{
					color[j]=color[edges[i].s];
				}
			}
		}
	}
	
	printf("%d\n", mstCost);

    system("pause");
}

