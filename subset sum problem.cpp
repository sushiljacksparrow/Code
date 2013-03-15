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

void subset_sum(int *arr, int len, int sum)
{
	int dp[len+1][sum+1];
	for(int i=0;i<len;i++)
		dp[i][0]=1;
	for(int i=1;i<=sum;i++)
		dp[0][i]=0;
	
	for(int i=1;i<len;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			int temp = j-arr[i];
			if(temp>=0)
			{
				dp[i][j]=dp[i-1][j]|dp[i-1][temp];
			} else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	
	cout<<dp[len-1][sum]<<endl;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int arr[50];
	int n, sum;
	cin>>n>>sum;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	subset_sum(arr, n, sum);
    system("pause");
}

