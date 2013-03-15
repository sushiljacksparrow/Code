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

void backtrack(int s[], int i)
{
	//system("pause");
	if(s[i]==-1)
		return;
	cout<<s[i]<<" ";
	backtrack(s, i-s[i]);
}

int solve(int val[], int v, int C)
{
	int dp[C+1];
	for(int i=1;i<=C;i++)
		dp[i]=9999;
	dp[0]=0;
	
	int s[C];
	s[0]=-1;
	
	for(int i=1;i<=C;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(i-val[j]>=0)
			{
				if(dp[i]>dp[i-val[j]]+1)
				{
					dp[i]=dp[i-val[j]]+1;
					s[i]=val[j];
				}
			}
		}
	}
	
	//for(int i=0;i<=C;i++)
	//	cout<<i<<" "<<s[i]<<endl;
	backtrack(s, C);
	cout<<endl;
	return dp[C];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	int val[]={1, 2, 3};
	cout<<solve(val, 3, 10)<<endl;

    system("pause");
}

