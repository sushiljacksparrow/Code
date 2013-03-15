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


int solve(int arr[], int n, int k)
{
	int dp[n+1][k+1];
	int sum[n];
	sum[0]=arr[0];
	for(int i=1;i<n;i++)
		sum[i]=sum[i-1]+arr[i];
		
	for(int i=1;i<=n;i++)
		dp[i][k]=sum[i-1];
	
	for(int i=1;i<=k;i++)
		dp[1][i]=arr[0];	
		
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=k;j++)
		{
			int ret = INT_MAX;
			for(int p=1;p<=n;p++)
			{
				ret = min(ret, max(dp[p][j-1], sum[j]-sum[p]));
			}
			dp[i][j]=ret;
		}
	}
	return dp[n][k];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int arr[]={100, 200, 300, 400, 500, 600 , 700, 800, 900};
	cout<<solve(arr, 9, 3)<<endl;

    system("pause");
}

