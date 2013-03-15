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
//#define OFF ios::sync_with_stdio(false)

using namespace std;
using namespace __gnu_cxx;

#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define ii pair<int,int>
#define vs vector<string>
#define all(v) (v).begin(), (v).end()
#define For(i,x) for(int i=0;i<x;i++)

#define MAX 2002

int cardsA[MAX], cardsB[MAX], dp[2][MAX];

int lcs(int len1, int len2)
{
	int i, j;
	for(j=0;j<=len2;j++)
		dp[0][j]=0;
	
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(cardsA[i-1]==cardsB[j-1])
				dp[i&1][j] = dp[!(i&1)][j-1]+1;
			else
				dp[i&1][j] = max(dp[!(i&1)][j], dp[i&1][j-1]);
		}
	}
	return dp[len1&1][len2];
}
	
int main()
{
    int t, len1, len2, n, best;
	scanf("%d", &t);
	while(t--)
	{
		len1 = best = 0;
		while(scanf("%d", &n)==1 && n)
			cardsA[len1++] = n;
		while(scanf("%d", &n)==1 && n)
		{
			len2 = 0;
			cardsB[len2++] = n;
			while(scanf("%d", &n)==1 && n)
				cardsB[len2++] = n;
			best = max(best, lcs(len1, len2));
		}
		printf("%d\n", best);
	}
	return 0;
}

