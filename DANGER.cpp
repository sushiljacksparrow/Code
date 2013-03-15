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


//int dp[99000001][2];

int solve(int n)
{
	if((n & (n-1)) == 0) return 1;
	if((n & 1) == 0) return (solve(n>>1)<<1)-1;
	return (solve((n-1)>>1)<<1)+1;
}
		
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	string str;
	while(cin>>str && str != "00e0")
	{
		int num = ((str[0]-'0')*10 + (str[1]-'0'))*pow(10.0, str[3]-'0');
//		memset(dp, -1, sizeof(dp));
		cout<<solve(num)<<endl;
	}
    system("pause");
}

