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

#define N 20

int solve(int arr[N], int n)
{
	int lis[N];
	for(int i=0;i<n;i++)
		lis[i]=1;

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && lis[i]<lis[j]+1)
				lis[i]=lis[j]+1;
		}
	}

	int lds[N];
	for(int i=0;i<n;i++)
		lds[i]=1;
	for(int i=n-2;i>=0;i--)
	{
		for(int j=n-1;j>i;j--)
		{
			if(arr[i]>arr[j] && lds[i]<lds[j]+1)
				lds[i]=lds[j]+1;
		}
	}
	
	int ret=1;
	for(int i=0;i<n;i++)
		ret=max(ret, lis[i]+lds[i]-1);
	return ret;
} 

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Length of LBS is %d\n", solve( arr, n ) );

    system("pause");
}

