/*Sushil Kumar Singh */
//http://www.spoj.pl/problems/PT07Y/
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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int n,m;
	vector< vector<int> > vvi(10001);
	bool visit[10001];
	memset(visit, false, sizeof(visit));
	cin>>n>>m;
	int u,v,t;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d", &u, &v);
		vvi[u].push_back(v);
	}
	stack<int>S;
	bool istree=true;
	S.push(1);
	while(!S.empty())
	{
		int t=S.top();
		S.pop();
		visit[t]=true;
		for(int i=0;i<vvi[t].size();i++)
		{
			if(visit[vvi[t][i]])
			{
				istree=false;
				break;
			}
			//visit[vvi[t][i]]=true;
			S.push(vvi[t][i]);
		}
	}
		
	// check if we visited everything
	for(int i=1;i<=n && istree == true;i++)
	{
		if(visit[i]==false)
		{
			//cout<<i<<endl;
			istree=false;
		}
	}
	
	if(istree)
	{
		cout<<"YES\n";
	}else
	{
		cout<<"NO\n";
	}
		
    system("pause");
}

