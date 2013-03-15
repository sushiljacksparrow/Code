// http://www.geeksforgeeks.org/median-of-two-sorted-arrays/
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


int median(int arr[], int n)
{
	if(n%2==0)
		return (arr[n/2] + arr[n/2-1])/2;
	else
		return arr[n/2];
}

int solve(int a[], int b[], int n)
{
	if(n<=0)
		return -1;
	if(n==1)
		return (a[0]+b[0])/2;
	if(n==2)
		return (max(a[0], b[0])+min(a[1], b[1]))/2;
	
	int m1 = median(a,n);
	int m2 = median(b, n);
	
	if(m1==m2)
		return m1;
	if(m1<m2)
	{
		if(n%2==0)
			return solve(a+n/2-1, b, n-n/2+1);
		else
			return solve(a+n/2, b, n-n/2);
	} else
	{
		if(n%2==0)
			return solve(b+n/2-1, a, n-n/2+1);
		else
			return solve(b+n/2, a, n-n/2);
	}
}
				
			
		
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int ar1[] = {1, 2, 3, 6};
    int ar2[] = {4, 6, 8, 10};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    
    cout<<solve(ar1, ar2, n1)<<endl;
    system("pause");
}

