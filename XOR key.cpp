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
int x[1000009];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	int test, n, q, a, p, r;
	cin>>test;
	while(test--)
	{
		scanf("%d %d", &n, &q);
		for(int i=0;i<n;i++)
			scanf("%d", &x[i]);
		for(int i=0;i<q;i++)
		{
			scanf("%d %d %d", &a, &p, &r);
			int t=a^x[p-1];
			for(int i=p;i<r;i++)
				t=max(t, x[i]^a);
			printf("%d\n", t);
		}
	}

    system("pause");
}

