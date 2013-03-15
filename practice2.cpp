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

int solve(int arr[], int s, int e)
{
	cout<<s<<" "<<e<<endl;
	if(s>e)
		return -1;
	if(s==e)
		return s;
	if(e==s+1)
		return e;
		
	int mid = (s+e)/2;
	if(mid%2!=0)
	{
		if(arr[mid] == arr[mid-1])
			return solve(arr, mid, e);
		else
			return solve(arr, s, mid-1);
	} else 
	{
		if(arr[mid]==arr[mid+1])
			return solve(arr, mid, e);
		else 
			return solve(arr, s, mid);
	}
}
		
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int arr[] = { 1, 2, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<solve(arr, 0, n-1)<<endl;

    system("pause");
}

