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

vector< pair< pair<int, int>, int> > paths;

void solve(int n, int m, int source, int target)
{
 	 bool visit[n+1]={false};
 	 int dist[n+1]={INT_MAX};
 	 dist[source]=0;
 	 visit[source]=true;
 	 
 	 queue<int>Q;
 	 while(!Q.empty())
 	 {
	  		int node = Q.front();
			for(int i=0;i<paths.size();i++)
			{
			 		if(paths[i].first.first==		  

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int n, m, k, s, t,x,y,v;
	pair< pair<int, int>, int> pp;
	pair<int, int> p;
	cin>>n>>m>>k>>s>>t;
	for(int i=0;i<m;i++)
	{
	 		cin>>pp.first.first>>pp.first.second>>pp.second;
			paths.push_back(pp);
	}
	
	solve(n, m, s, t);

    system("pause");
}

