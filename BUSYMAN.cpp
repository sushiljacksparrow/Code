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

bool cmp( const ii& a, const ii& b)
{
	if( b.second == a.second )
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	
	int n,test;
	cin>>test;
	pair<int, int> vp[100009];
	while(test--)
	{
		cin>>n;
		//vector< pair<int, int> > vp(n);
		for(int i=0;i<n;i++)
		{
			//cin>>vp[i].first>>vp[i].second;
			scanf("%d %d", &vp[i].first, &vp[i].second);
		}
		sort(vp, vp+n, cmp);
		
		int res=0, currentTime=-1;
		for(int i=0;i<n;i++)
		{
			if(vp[i].first>=currentTime)
			{
				res++;
				currentTime=vp[i].second;
			}
		}
		cout<<res<<endl;	
	}
    system("pause");
}

