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


int solve(int n, int k)
{
	int dp[n+1][k+1];
	for(int i=0;i<=k;i++)
		dp[0][i]=0;
	for(int i=0;i<=n;i++)
		dp[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			int sum=0;
			for(int r=0;r<i && j-r>=0;r++)
			{
				sum+=dp[i-1][j-r];
			}
			dp[i][j]=sum;
		}
	}	
	
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<=k;j++)
//		{
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return dp[n][k];
}

int dp[20][100];
int count(int n, int k)
{
	if(n == 0)
		return 0;
	if(k == 0)
		return 1;
	if(dp[n][k] != -1)
		return dp[n][k];
	int val = 0;
	for(int i = 0; i < n && k-i >= 0; i++)
		val += count(n-1,k-i);
	return (dp[n][k] = val);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int t, n, k;
	cin>>t;
	
	while(t--)
	{
		memset(dp, -1, sizeof(dp));
		cin>>n>>k;
		cout<<solve(n,k)<<endl;
	}

    system("pause");
}

