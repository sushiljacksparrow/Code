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

bool solve(int arr[], int n)
{
	int s=0;
	for(int i=0;i<n;i++)
		s+=arr[i];
	
	int dp[n][s+1];
	for(int i=0;i<=s;i++)
		dp[0][i]=0;
		
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=s;j++)
		{
			if(j-arr[i]>=0)
			{
				dp[i][j]=max(dp[i-1][j], dp[i-1][j-arr[i]]);
			}
		}
	}
	
	int half = s/2;
	for(int i=0;i<n;i++)
		if(dp[i][half])
			return 0;
	  
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

