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

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int rotate(int arr[], int d, int n)
{
	int g = gcd(n, d);
	int temp, s, t;
	for(int i=0;i<g;i++)
	{
		temp = arr[i];
		s=i;
		while(1)
		{
			t=s+d;
			if(t>=n)
				t-=n;
			if(t==i)
				break;
			arr[s]=arr[t];
			s=t;
		}
		arr[s]=temp;
	}
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
	rotate(arr, 4, 12);
	for(int i=0;i<12;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

    system("pause");
}

