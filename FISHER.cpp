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

const int INF = 0x3fffffff;
	

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int C[51][51], T[51][51];
	int N, deadline;
	int dp[1001][51];

	while (scanf("%d %d", &N, &deadline) == 2 && N > 0)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &T[i][j]);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &C[i][j]);

		for (int t = 0; t <= deadline; t++)
			for (int i = 0; i < N; i++)
				dp[t][i] = INF;
		dp[0][0] = 0;

		int bestToll = INF, bestTime = INF;
		
		for(int t=0;t<=deadline;t++)
		{
			for(int i=0;i<N;i++)
			{
				if(dp[t][i]==INF)
					continue;
				
				if(t<deadline)
					dp[t+1][i] = min(dp[t+1][i], dp[t][i]);
				for(int j=0;j<N;j++)
				{
					if(t+T[i][j]<=deadline)
					{
						int tt = t + T[i][j];
						dp[tt][j] = min(dp[tt][j], dp[t][i]+C[i][j]);
					}
				}
			}
			//cout<<dp[t][N-1]<<endl;
			if(dp[t][N-1]<bestToll)
			{
				bestToll = dp[t][N-1];
				bestTime = t;
			}
		}
	
		cout<<bestToll<<" "<<bestTime<<endl;
	}
	system("pause");
}



