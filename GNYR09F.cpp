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
#define i64 long long


i64 dp[110][110][2];

i64 solve(int pos, int total, int prev)
{
	if(total<0)
		return 0;
	if(pos<0)
	{
		if(total==0)
			return 1;
		return 0;
	}	
	
	i64 &ret = dp[pos][total][prev];
	if(ret != -1)
		return ret;
	ret = 0;
	if(prev == 1)
	{
		ret += solve(pos-1, total-1, 1);
		ret += solve(pos-1, total, 0);
	} else
	{
		ret += solve(pos-1, total, 1);
		ret += solve(pos-1, total, 0);
	}
	
	return ret;
}

int main()
{
    
	int test, cs, n, k;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d %d %d", &cs, &n, &k);
		printf("%d ", cs);
		memset(dp, -1, sizeof(dp));	

		i64 ret = solve(n-2, k, 1);
		ret += solve(n-2, k, 0);
		cout<<ret<<endl;
	}
	
    system("pause");
}

