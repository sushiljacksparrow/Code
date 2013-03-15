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

int search(int arr[], int low, int high, int key)
{
	int mid;
	while(high-low>1)
	{
		mid = low + (high-mid)/2;
		if(arr[mid]>=key)
			low=mid;
		else
			high=mid;
	}
	return mid;
}

int solve(int arr[], int n)
{
	int temp[n];
	temp[0]=0;
	int len=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]<temp[0])
		{
			temp[0]=arr[i];
		} else if(arr[i]>temp[len-1])
		{
			temp[len++] = arr[i];
		} else
		{
			temp[search(temp, -1, len-1, arr[i])]=arr[i];
		}
	}
	delete[] temp;
	return len;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int A[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
	int len=sizeof(A)/sizeof(A[0]);
	
	cout<<solve(A, len)<<endl;
    system("pause");
}

