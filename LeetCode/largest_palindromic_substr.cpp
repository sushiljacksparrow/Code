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


string palindrome(string str)
{
	int n = str.size();
	int dp[n][n];
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<n;i++)
		dp[i][i]=1;
	int beg=0, end=0, maxlen = 1;
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			cout<<i<<" "<<j<<endl;
			if(j==i+1 && str[i]==str[j])
				dp[i][j]=1;
			else if(dp[i+1][j-1]==1 && str[i]==str[j])
				dp[i][j]=1;
			if(maxlen < j-i && dp[i][j])
			{
				maxlen = j-i;
				beg = i;
				end = j;
			}
		}
	}
	return str.substr(beg, end-beg+1);
}
			
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	string str;
	while(cin>>str)
		cout<<palindrome(str)<<endl;

    system("pause");
}

