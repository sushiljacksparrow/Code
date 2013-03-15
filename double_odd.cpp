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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int n,xor1=0,x=0,y=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	 	cin>>arr[i];
	 	xor1^=arr[i];
	}
	int last_set_bit=xor1 & ~(xor1-1);
	cout<<last_set_bit<<endl;
	for(int i=0;i<n;i++)
	{
	 	if(arr[i]&last_set_bit)
            x=x^arr[i];
		else
			y=y^arr[i];
	}
	cout<<x<<" "<<y<<endl;			
    system("pause");
}

