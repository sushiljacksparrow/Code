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

int kadane(int arr[], int n)
{
	int current_sum = 0, global_sum = INT_MIN;
	for(int i=0;i<n;i++)
	{
		current_sum += arr[i];
		if(current_sum < 0)
			current_sum = 0;
		if(global_sum < current_sum)
			global_sum = current_sum;
	}
	return global_sum;
}

int solve(int arr[], int n)
{
	int f = kadane(arr, n);
	int temp[n];
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum += arr[i];
		temp[i] = -1*arr[i];
	}
	int t = kadane(temp, n);
	return max(f, sum+t);
}

int maximum_product_subarray(int arr[], int n)
{
	int max_product = 1, min_product = 1;
	int global_max = INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<0)
		{
			int temp = max_product;
			max_product = max(min_product*arr[i], 1);
			min_product = temp * arr[i];
		} else if(arr[i]==0)
		{
			max_product = 1;
			min_product = 1;
		} else
		{
			max_product = arr[i]*max_product;
			min_product = min(arr[i]*min_product, 1);
		}
		if(global_max < max_product)
			global_max = max_product;
		cout<<max_product<<" "<<min_product<<endl;
	}
	return global_max;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int a[] = {6, -3, -10, 0, 2};
	cout<<maximum_product_subarray(a, sizeof(a)/sizeof(a[0]))<<endl;

    system("pause");
}

