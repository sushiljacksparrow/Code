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


void bucket_sort(int arr[], int n, int k)
{
	int temp[k+1];
	memset(temp, 0, sizeof(temp));
	for(int i=0;i<n;i++)
		temp[arr[i]]++;
	for(int i=1;i<=k;i++)
		temp[i] += temp[i-1];
		
	int r = 1;
	int cn = 0;
	while(r<=k)
	{
		int d = temp[r]-temp[r-1];
		while(d--)
			arr[cn++] = r;
		r++;
	}
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}
		
		
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int arr[] = {1, 1, 1, 3, 4, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	bucket_sort(arr, 6, 5);
    system("pause");
}

