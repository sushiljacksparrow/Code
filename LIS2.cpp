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


int find_ceil(int temp[], int l, int r, int key)
{
	int m;
	while(r-l>1)
	{
		m = l + (r-l)/2;
		if(temp[m] >= key)
			r = m;
		else
			l = m;
	}
	return r;
}

void LIS(int arr[], int n)
{
	int temp[n];
	memset(temp, 0, sizeof(temp));
	temp[0] = arr[0];
	int len = 1;
	for(int i=1;i<n;i++)
	{
		if(temp[0]>arr[i])
			temp[0] = arr[i];
		else if(temp[len-1] < arr[i])
			temp[len++] = arr[i];
		else
		{
			int t = find_ceil(temp, -1, len-1, arr[i]);
			temp[t] = arr[i];
		}
	}
	cout<<len<<endl;
}

int find_ceil_new(int arr[], int tail[], int l, int r, int key)
{
	int m;
	while(r-l>1)
	{
		m = l + (r-l)/2;
		if(arr[tail[m]]>key)
			r = m;
		else
			l = m;
	}
	return r;
}

void LIS_PRINT(int arr[], int n)
{
	int tail[n], prev[n], len = 1;
	memset(tail, 0, sizeof(tail));
	memset(prev, 0xFF, sizeof(prev));
	tail[0] = 0;
	prev[0] = -1;
	
	
	for(int i=1;i<n;i++)
	{
		if(arr[i] < arr[tail[0]])
			tail[0] = i;
		else if(arr[i] > arr[tail[len-1]])
		{
			prev[i] = tail[len-1];
			tail[len++] = i;
		} else
		{
			int pos = find_ceil_new(arr, tail, -1, len-1, arr[i]);
			prev[i] = tail[pos-1];
			tail[pos] = i;
		}
	}
	
	printf("LIS of the given sequence\n");
	for(int i=tail[len-1];i>=0; i = prev[i])
		printf("%d ", arr[i]);
	cout<<endl;
}
			
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	int A[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    int n = sizeof(A)/sizeof(A[0]);
 
	LIS_PRINT(A, n);

    system("pause");
}

