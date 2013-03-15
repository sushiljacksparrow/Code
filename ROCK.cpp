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


string str;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int n, test, cnt, add;
	cin>>test;
	int dp[256];
	char str[256];
	while(test--)
	{
		scanf("%d %s", &n, str);
		dp[0]=str[0]-'0';
		
		for(int i=1;i<n;i++)
		{
			dp[i]=dp[i-1];
			cnt = 0;
			for(int j=i;j>=0;j--)
			{
				cnt += (str[j]=='1') ? 1: -1;
				if(cnt > 0)
				{
					add = i-j+1;
					if(j>0)
						add += dp[j-1];
					dp[i] = max(dp[i], add);
				}
			}
		}
		printf("%d\n", dp[n-1]);
	}	
    system("pause");
}

