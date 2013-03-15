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

// there will be n symbols and n-1 ops
int solve(char symb[], char ops[], int n)
{
	int dp[n][n];
	for(int i=0;i<n;i++)
	{
		if(symb[i]=='T')
			dp[i][i]=1;
		else
			dp[i][1]=0;
	}
	
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			int ways=0;
			for(int k=i;k<j;k++)
			{
				int t;
				if(ops[k]=='O')
					ways += dp[i][k] || dp[k+1][j];
				else if(ops[k]=='A')
					ways += dp[i][k] && dp[k+1][j];
				else 
					ways += dp[i][k] xor dp[k+1][j];
			}
			dp[i][j]=ways;
		}
	}
	
	return dp[0][n-1];
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

