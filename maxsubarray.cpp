// http://www.geeksforgeeks.org/archives/20586
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


#define N 1000

int solve(int arr[N], int n)
{
	int maxSize = -1, min=INT_MAX, max=INT_MIN, startIndex;
	int sumleft[N];
	sumleft[0]=arr[0]==1 ? 1 : -1;
	for(int i=1;i<n;i++)
	{
		sumleft[i]=sumleft[i-1]+ + arr[i]==1 ? 1 : -1;
		if(min > sumleft[i])
			min=sumleft[i];
		if(max < sumleft[i])
			max=sumleft[i];
	}
	
	int hash[max-min+1];
	memset(hash, -1, sizeof(hash));
	
	for(int i=0;i<n;i++)
	{
		if(sumleft[i]==0)
		{
			maxSize = i+1;
			startIndex = 0;
		}
		
		if(hash[sumleft[i]-min]==-1)
			hash[sumleft[i]-min] = i;
		else
		{
			if(i-hash[sumleft[i]-min] > maxSize)
			{
				maxSize = i- hash[sumleft[i]-min];
				startIndex = hash[sumleft[i]-min];
			}
		}
	}
	return maxSize;
}
	
	
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

