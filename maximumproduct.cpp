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


int maximum_product(int arr[], int n)
{
	int max_end_here = 1, min_end_here = 1, max_so_far = 1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>0)
		{
			max_end_here = max_end_here * arr[i];
			min_end_here = max(min_end_here*arr[i], 1);
		} else if(arr[i] == 0)
		{
			max_end_here = 1;
			min_end_here = 1;
		} else
		{
			int t = max_end_here;
			max_end_here = max(min_end_here*arr[i], 1);
			min_end_here = t * arr[i];
		}
		
		if(max_end_here > max_so_far)
			max_so_far = max_end_here;
	}
	return max_so_far;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maximum_product(arr, n)<<endl;
    system("pause");
}

