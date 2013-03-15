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

int MAXN = 100;
int MAXK = 100;

void print_books(int *arr, int start, int end)
{
	int i;
	for(i=start; i<=end;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void reconstruct_partition(int arr[MAXN+1], int s[MAXN+1][MAXK+1], int n, int k)
{
	if(k==1)
		print_books(arr, 1, n);
	else
	{
		reconstruct_partition(arr, s, s[n][k], k-1);
		print_books(arr, s[n][k]+1, n);
	}
}


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int arr[MAXN+1];
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	
//	cout<<arr[1]<<endl;
	int dp[MAXN+1][MAXK+1], s[MAXN+1][MAXK+1];
	int p[n+1];
	p[0]=0;
	for(int i=1;i<=n;i++)
		p[i]=p[i-1]+arr[i];
		
	for(int i=1;i<=n;i++)
		dp[i][1]=p[i];
	for(int i=1;i<=k;i++)
		dp[1][i]=arr[1];
	
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=k;j++)
		{
			dp[i][j]=99999;
			for(int k=1;k<=i-1;k++)
			{
				int cost=max(dp[k][j-1], p[i]-p[k]);
				if(dp[i][j] > cost)
				{
					dp[i][j]=cost;
					s[i][j]=k;
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	reconstruct_partition(arr, s, n, k);

    system("pause");
}

