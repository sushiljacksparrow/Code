//http://www.geeksforgeeks.org/archives/19155
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


void solve(string str)
{
	int n = str.size();
	int dp[n+1][n+1];
	for(int i=0;i<n;i++)
		dp[i][i]=1;
		
	for(int l=2;l<n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			if(j==i+1 && str[i]==str[j])
				dp[i][j]=2;
			else if(str[i]==str[j])
			{
				dp[i][j]=dp[i+1][j-1]+2;
			} else
			{
				dp[i][j]=max(dp[i][j-1], dp[i+1][j]);
			}
		}
	}
	
	cout<<dp[0][n-1]<<endl;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

