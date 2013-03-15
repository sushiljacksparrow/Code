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

#define N 1024

int vm[N], vn[N];

int main()
{
	int test, sm, sn, ans, m, n;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d %d", &m, &n);
		sm=sn=ans=0;
		for(int i=1;i<m;i++)	scanf("%d", &vm[i]), sm+=vm[i];
		for(int i=1;i<n;i++)	scanf("%d", &vn[i]), sn+=vn[i];
		
		sort(vm+1, vm+m); sort(vn+1, vn+n);
		m--; n--;
		while(m||n)
		{
			if(vm[m]>vn[n])	ans+=vm[m]+sn, sm-=vm[m--];
			else			ans+=vn[n]+sm, sn-=vn[n--];
		}
		
		printf("%d\n", ans);
	}
			
	system("pause");
}

