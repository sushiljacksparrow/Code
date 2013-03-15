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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int t, n,m,s,e,x,y,v;
	ii p;
	cin>>t;
	while(t--)
	{
	 	cin>>n>>m>>s>>e;
		vvii paths(n+1);
		for(int i=0;i<m;i++)
		{
		 	cin>>x>>y>>v;
			p.first=y; p.second=v;
			paths[x].push_back(p);
		}
		
		for(int i=1;i<paths.size();i++)
		{
		 	cout<<i<<" -- ";
			for(int j=0;j<paths[i].size();j++)
			{
			 	cout<<"("<<paths[i][j].first<<" "<<paths[i][j].second<<")";
			}
			cout<<endl;
		}	 	
		
		vi D(n+1, 987654321);
		priority_queue< ii, vector<ii>, greater<ii> > Q;	 	 	  
		D[s]=0;
		Q.push(ii(s,0));
		
		while(!Q.empty())
		{
		 	ii top = Q.top();
			Q.pop();
			int v=top.first, d=top.second;
			cout<<v<<" "<<d<<endl;
			if(d<=D[v])
			{
			 	for(int i=0;i<paths[v].size();i++)
		        {
				 	ii temp = paths[v][i];
					int v2 = temp.first, cost=top.second;
					cout<<"inserting "<<v2<<" "<<cost<<endl;
					if(D[v2]>D[v]+cost)
					{
					 	D[v2]=D[v]+cost;
						Q.push(ii(v2, D[v2]));
					}
			    }
			}
		}
		if(D[e]!=987654321)
            cout<<"NONE"<<endl;			  			   			 
        else 
            cout<<D[e]<<endl;
    }
    system("pause");
}

