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

void two_xors(int arr[], int n)
{
	int x = arr[0];
	for(int i=1;i<n;i++)
		x=x xor arr[i];
	int index = 0;
	for(int i=0;i<32;i++)
		if(x&(1<<i))
			{index = i; break;}
//	cout<<x<<" "<<index<<endl;
	int a=0, b=0;
	for(int i=0;i<n;i++)
		if(arr[i]&(1<<index))
			a= a xor arr[i];
		else
			b= b xor arr[i];
	cout<<a<<" "<<b<<endl;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int arr[] = {4, 2, 4, 5, 2, 3, 3, 1};
	two_xors(arr, sizeof(arr)/sizeof(arr[0]));
    system("pause");
}

