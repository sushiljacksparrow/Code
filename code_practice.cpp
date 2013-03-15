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

int find_ceil(int arr[], int index[], int l, int r, int key)
{
	int m;
	while(r-l>1)
	{
		m = l + (r-l)/2;
		if(arr[index[m]] >= key)
			r = m;
		else
			l = m;
	}
	return r;
}

int LongestIncreasingSubsequence(int arr[], int n)
{
	int index[n], prevIndex[n];
	index[0] = 0, prevIndex[0] = -1;
	int len = 1;
	for(int i=1;i<n;i++)
	{
		if(arr[i] < arr[index[0]])
		{
			index[0] = i;
		} else if(arr[i] > arr[index[len-1]])
		{
			prevIndex[i] = index[len-1];
			index[len++] = i;
		} else 
		{
			int ceil = find_ceil(arr, index, 0, len-1, arr[i]);
			prevIndex[i] = index[ceil-1];
			index[ceil] =  i;
		}
	}
	
	for(int i=index[len-1];i>=0; i = prevIndex[i])
		cout<<arr[i]<<endl;
	return len;
}
			
			

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int A[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    int size = sizeof(A)/sizeof(A[0]);
 
    printf("LIS size %d\n", LongestIncreasingSubsequence(A, size));

    system("pause");
}

