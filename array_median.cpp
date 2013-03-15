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

// when the array is of the same size
int median(int a[], int b[], int n)
{
	int al = 0, ar = n-1, bl = 0, br = n-1;
	while(ar-al>2 && br-bl>2)
	{
		int ma = (ar+al)/2;
		int mb = (br+bl)/2;
		if(a[ma]==b[mb])
			return a[ma];
		else
		{
			if(a[ma]>b[mb])
			{
				al = ma; br = mb;
			} else 
			{
				ar = ma; bl = mb;
			}
		}
	}
	return (max(a[al], b[bl]) + min(a[ar], b[br]))/2;
}

int getMedian(int arr[], int l, int r)
{
	if((r-l)%2)
		return (arr[(l+r)/2]+arr[(l+r)/2+1])/2;
	else
		return arr[(l+r)/2];
}

int median_different(int a[], int an, int b[], int bn)
{
	if(bn==1)
	{
		if(an==1)
			return (a[0]+b[0])/2;
		else if(an%2)
			return MO2(B[0], MO3(B[0], A[an/2-1], A[an/2+1]));
		return MO3(A[an/2], A[an/2-1], B[0]);
	} else if(bn==2)
	{
		if(an==2)
		{
			
				
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int a[] = {1, 12, 15, 26, 38};
    int b[] = {2, 13, 17, 30, 45};
	cout<<median(a, b, sizeof(a)/ sizeof(a[0]))<<endl;

    system("pause");
}

