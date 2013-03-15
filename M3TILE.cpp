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
	long long arr[31]={0};
	arr[0]=1;
	arr[1]=0;
	arr[2]=3;
	arr[3]=0;
	arr[4]=11;
	
	for(int x=6;x<=30;x+=2)
	{
		arr[x] = arr[x] + arr[x-2]*3;
		for(int y=x-4;y>=0;y-=2)
		{
			arr[x] = arr[x] + 2*arr[y];
		}
	}
	int n;
	cin>>n;
	while(n!=-1)
	{
		cout<<arr[n]<<endl;
		cin>>n;
	}
	
	system("pause");
}

