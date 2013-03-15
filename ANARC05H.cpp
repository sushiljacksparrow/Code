/*Sushil Kumar Singh */
/* http://www.spoj.com/problems/ANARC05H/ */
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


int len, dp[32][256];
char num[32];
	
int solve(int pos, int prev)
{
	if(pos==len)
		return 1;
	int &ret = dp[pos][prev];
	if(ret!=-1)
		return ret;
	ret = 0;
	
	for(int i=pos, sum=0;i<len;i++)
	{
		sum+=(num[i]-'0');
		if(sum>=prev)
			ret += solve(i+1, sum);
	}
	return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int cs = 1;
	while(scanf("%s", num)==1 && isdigit(num[0]))
	{
		memset(dp, -1, sizeof(dp));
		len = strlen(num);
		printf("%d. %d\n", cs++, solve(0,0));
	}
	system("pause");
}

