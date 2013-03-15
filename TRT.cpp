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

int dp[2001][2001];
int cost[2001];
int n;

int func(int i, int j)
{
	if(dp[i][j]!=-1)
		return dp[i][j];
	
	int m = j-i+1;
	m = n-m+1;
	
	if(i==j)
		return cost[i]*m;
		
	dp[i][j] = max(m*cost[i]+func(i+1, j), m*cost[j]+func(i, j-1));
	return dp[i][j];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	

	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>cost[i];
		
	memset(dp, -1, sizeof(dp));
	//int ans = func(0,n-1);	
	
	for(int i=0;i<n;i++)
		dp[i][i]=cost[i];
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			int age = j-i+1;
			
			
			//age = n-age+1;
			cout<<i<<" "<<j<<" "<<age<<endl;
			dp[i][j]=max(dp[i+1][j]+cost[i]*age, dp[i][j-1]+cost[j]*age);
		}
	}
	
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[0][n-1]<<endl;
    system("pause");
}

