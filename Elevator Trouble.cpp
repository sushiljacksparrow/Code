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
int dp[1000001] = {INT_MAX};
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int f, s, g, u, d;
	cin>>f>>s>>g>>u>>d;
	for(int i=1;i<=f;i++)
		dp[i]=INT_MAX;
	dp[s] = 0;
	
	queue<int>Q;
	Q.push(s);

	while(!Q.empty())
	{
		int t = Q.front();
		//cout<<t<<" ";
		Q.pop();
		if(t==g)
			break;
		if(t+u <= f && dp[t+u]==INT_MAX)
		{
			dp[t+u]=dp[t]+1;
			Q.push(t+u);
		}
		if(t-d>=1 && dp[t-d]==INT_MAX)
		{
			dp[t-d]=dp[t]+1;
			Q.push(t-d);
		}
	}
	
	if(dp[g]!=INT_MAX)
		cout<<dp[g]<<endl;
	else
		cout<<"use the stairs\n";
	
	system("pause");
}

