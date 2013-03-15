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


struct pai
{
	int first, second;
};

int find_ceil(pai arr[], int tail[], int l, int r, pai key)
{
	int m;
	while(r-l>1)
	{
		m = l + (r-l)/2;
		if(arr[tail[m]].first >= key.first)
			r = m;
		else
			l = m;
	}
	return r;
}

void LIS(pai arr[], int n)
{
	int tail[n], last_index[n];
	memset(tail, 0, sizeof(tail));
	memset(last_index, 0xff, sizeof(last_index));
	last_index[0] = -1;
	tail[0] = 0;
	int len = 1;
	for(int i=1;i<n;i++)
	{
		if(arr[i].first < arr[tail[0]].first)
		{
			tail[0] = i;
		} else if(arr[i].first > arr[tail[len-1]].first)
		{
			last_index[i] = tail[len-1];
			tail[len++] = i;
		} else 
		{
			int ceil = find_ceil(arr, tail, -1, len-1, arr[i]);
			last_index[i] = tail[len-1];
			tail[len++] = ceil;
		}
	}
	
	for(int i=tail[len-1];i>=0;i = last_index[i])
		cout<<arr[i].first<<" "<<arr[i].second<<"\n";

}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	pai arr[] = { {5, 24}, {15, 25},
                          {27, 40}, {50, 60} };
	LIS(arr, 4);					  	
	
	
    system("pause");
}

