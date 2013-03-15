/*Sushil Kumar Singh */
//http://www.spoj.pl/problems/PFDEP/
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


int mat[101][101];
bool visit[101];
int finish[101];
int n, m;
int tim=0;
void dfs(int node)
{
	tim++;
//	cout<<node<<" "<<tim<<endl;
	if(visit[node])
		return;
	for(int i=1;i<=n;i++)
	{
		if(mat[node][i]==1 && visit[i]==false)
		{
//			tim++;
			dfs(i);
		}
	}
	tim++;
	finish[node]=tim;
	visit[node]=true;
//	cout<<node<<" "<<tim+1<<endl;
}

bool cmp(const pair<int, int> p1, const pair<int, int> p2)
{
//	if(p1.first==p2.first)
//		return p1.second < p2.second;
//	else
		return p1.second < p2.second;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	
	scanf("%d %d", &n, &m);
	int from, k, to;
	memset(mat, 0, sizeof(mat));
	for(int i=0;i<m;i++)
	{
		scanf("%d %d", &from, &k);
		while(k--)
		{
			scanf("%d", &to);
			mat[from][to]=1;
		}
	}
	memset(visit, false, sizeof(visit));
	for(int i=1;i<=n;i++)
	{
		if(!visit[i])
		{
//			tim=0;
			dfs(i);
		}
	}
	vector< pair<int, int> > pairs(n);
	for(int i=1;i<=n;i++)
	{
		pairs[i-1].first=i;
		pairs[i-1].second=finish[i];
	}
	
	sort(pairs.begin(), pairs.end(), cmp);
	cout<<pairs[0].first<<" "<<pairs[0].second<<endl;
	for(int i=1;i<n;i++)
		cout<<" "<<pairs[i].first<<" "<<pairs[1].second<<endl;
		cout<<endl;
    system("pause");
}

