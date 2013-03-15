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

int solve(string str)
{
	int n=str.size();
	int dp[n+1][n+1];
	int pal[n+1][n+1];
	memset(pal, 0, sizeof(pal));
	for(int i=0;i<n;i++)
		{dp[i][i]=0; pal[i][i]=1;}
	
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			if(l==2)
				pal[i][j] = (str[i]==str[j]);
			else
				pal[i][j] = pal[i+1][j-1] && (str[i]==str[j]);
			if(pal[i][j]==1)
				dp[i][j]=0;
			else
			{
				dp[i][j]=INT_MAX;
					for(int k=i;k<j;k++)
					{
						dp[i][j]=min(dp[i][j], dp[i][k] + 1 + dp[k+1][j]);
					}
			}
		}
	}
	
	return dp[0][n-1];
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	cout<<solve("ababbbabbababa")<<endl;
    system("pause");
}

