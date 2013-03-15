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

unsigned long long binomial_coffivients(int n, int k)
{
	int dp[100][100];
	for(int i=0;i<100;i++)
		dp[i][0]=1;
	for(int i=1;i<=n;i++)
		dp[i][i]=1;
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<i;l++)
		{
			dp[i][l]=dp[i-1][l-1]+dp[i-1][l];
		}
	}
	return dp[n][k];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int n, k;
	while(cin>>n>>k)
		cout<<binomial_coffivients(n,k)<<endl;
		
    system("pause");
}

