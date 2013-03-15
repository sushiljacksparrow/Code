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

int search(int arr[], int l, int r, int key)
{
	int m;
	while(r-l>1)
	{
		m = l+(r-l)/2;
		if(arr[m]>=key)
			r=m;
		else
			l=m;
	}
	return r;
}

int LIS(int arr[], int n)
{
	int temp[n];
	int len=1;
	temp[0]=arr[0];
	
	for(int i=1;i<n;i++)
	{
		if(arr[i]<temp[0])
		{
			temp[0]=arr[i];
		} else if(arr[i]>temp[len-1])
		{
			temp[len++]=arr[i];
		} else
		{
			temp[search(arr, -1, len-1, arr[i])]=arr[i];
		}
	}
	delete[] temp;
	return len;
}
		
int solve(int X[], int Y[], int n)
{
	int lisx=LIS(X, n);
	int lisy=LIS(Y,n);
	return min(lisx, lisy);	
}
	
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int X[]={8,1,4,3,5,2,6,7};
	int Y[]={1,2,3,4,5,6,7,8};
	
	cout<<solve(X, Y, 8)<<endl;

    system("pause");
}

