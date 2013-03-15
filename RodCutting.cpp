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

#define N 10
int solve(int len[N], int p[N], int n)
{
	int dp[n+1];
	dp[0]=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i]=dp[i-1];
			if(i>=len[j] && dp[i-len[j]] + p[j] >= dp[i])
				dp[i]=dp[i-len[j]]+p[j];
		}
	}
	
	for(int i=0;i<=n;i++)
		cout<<dp[i]<<" ";
	cout<<endl;
	return dp[n];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int len[]={1,2,3,4,5,6,7,8};
	int p[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(p)/sizeof(p[0]);
    printf("Maximum Obtainable Value is %d\n", solve(len, p, size));

    system("pause");
}

