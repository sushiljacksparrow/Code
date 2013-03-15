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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	int n, p, q, s;
	map<int, int>m;
	int test=1;
	while(cin>>n && n!=0)
	{
		vector< vector<int> > vvi(n+1);
		cin>>s;
		while(cin>>p>>q && p!=0 && q!=0)
		{
			vvi[p].push_back(q);
		}
		
		queue<int>Q;
		Q.push(s);
		m[s]=0;
		int ret=-1, node = -1;
		while(!Q.empty())
		{
			int r = Q.front();
			int d = m[r];
			
			//cout<<r<<"--- "<<d<<endl;
			Q.pop();
			if(ret<d)
			{
				ret = d;
				node = r;
			}
			//ret=max(ret, d);
			
			int len = vvi[r].size();
			for(int i=0;i<len;i++)
			{
				Q.push(vvi[r][i]);
				m[vvi[r][i]]=d+1;
			}
		}
		
		cout<<"Case "<<test<<": The longest path from "<<s<<" has length "<<ret<<", finishing at "<<node<<"."<<endl;
		test++;
	}	
	

    system("pause");
}

