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

#define INF 9999
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int dp[101][251];
	int time[101][251];
	int risk[101][251];
	
	int n, t, test;
	cin>>test;
	while(test--)
	{
		cin>>n>>t;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>time[i][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>risk[i][j];
		memset(dp, INF, sizeof(dp));
		for(int i=0;i<=t;i++)
			dp[0][i]=0;
		
		for(int i=1;i<=t;i++)
		{
			for(int j=0;j<n;j++)
			{
				dp[j][i] = dp[j][i-1];
				for(int k=0;k<n;k++)
				{
					if(i-time[j][k]>=0)
						dp[j][i] = min(dp[j][i], dp[k][i-time[j][k]]+risk[k][j]);
				}
			}
		}
								
//		for(int i=0;i<n;i++)
//		{
//			for(int j=0;j<=t;j++)
//			{
//				cout<<dp[i][j]<<"\t";
//			}
//			cout<<endl;
//		}
		int min_time=INF, min_risk=INF;
		for(int i=0;i<=t;i++)
		{
			if(min_risk>dp[n-1][i])
			{
				min_risk = dp[n-1][i];
				min_time = i;
			}
		}
		if(min_risk != INF)
			cout<<min_risk<<" "<<min_time<<endl;
		else
			cout<<-1<<endl;
	}	
			

    system("pause");
}

