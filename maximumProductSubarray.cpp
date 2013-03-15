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

int solve(vector<int>arr)
{
	int len=arr.size();
	vector<int>res(len);
	int maxEnd = 1;
	int minEnd = 1;
	
	int maxSoFar = 1;
	
	for(int i=0;i<len;i++)
	{
		if(arr[i]>0)
		{
			maxEnd = maxEnd*arr[i];
			minEnd = min(minEnd*arr[i], 1);
		} else if(arr[i]==0)
		{
			maxEnd = 1;
			minEnd = 1;
		} else
		{
			int temp=maxEnd;
			maxEnd = max(minEnd*arr[i], 1);
			minEnd = maxEnd*arr[i];
		}
		
		maxSoFar = max(maxEnd, maxSoFar);
	}
	
	return maxSoFar;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

