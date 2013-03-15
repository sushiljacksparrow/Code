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

int best[101][101];
int dp[2][101];
	
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int t, h, w;
	scanf("%d", &t);

	int arr[3] = {-1,0,1};
	while(t--)
	{
		scanf("%d %d", &h, &w);
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				scanf("%d", &best[i][j]);
				
		for(int i=0;i<w;i++)
			dp[0][i] = best[0][i];
		
		for(int i=1;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				int t = INT_MIN;
				for(int k=0;k<3;k++)
				{
					if(j+arr[k]>=0 && j+arr[k]<w)
						t = max(t, dp[!(i&1)][j+arr[k]]);
				}
				dp[i&1][j] = t+best[i][j];
			}
		}
		int ans = INT_MIN;
		for(int i=0;i<w;i++)
			ans = max(ans, dp[!(h&1)][i]);
		printf("%d\n", ans);					
	}
    system("pause");
}

