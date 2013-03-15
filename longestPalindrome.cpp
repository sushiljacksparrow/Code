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


string longestPalindrome(string str)
{
	int l=str.size();
	int dp[l][l];
	memset(dp, 0, sizeof(dp));
	
	for(int i=0;i<l;i++)
		dp[i][i]=1;
	int maxlen=1, begin=0;
	for(int i=0;i<l-1;i++)
		if(str[i]==str[i+1])
			maxlen=2, begin=i, dp[i][i+1]=1;
			
	for(int len=3;len<=l;len++)
	{
		for(int i=0;i<l-len+1;i++)
		{
			int j=i+len-1;
			if(str[i]==str[j] && dp[i+1][j-1]==1)
			{
				dp[i][j]=1;
				begin=i;
				maxlen=len;
			}
		}
	}
	return str.substr(begin, maxlen);
}


string expand(string str, int l, int r)
{
	int n=str.size();
	while(l>=0 && r<=n-1 && str[l]==str[r])
		l--, r++;
	return str.substr(l+1, r-l-1);
}
	
string longestPalindrome2(string str)		
{
	int n=str.size();
	string ret="";
	if(n==0)
		return ret;
	ret=str.substr(0,1);
	for(int i=0;i<n-1;i++)
	{
		string p=expand(str, i, i);
		if(p.size()>ret.size())
			ret=p;
		p=expand(str, i, i+1);
		if(p.size()>ret.size())
			ret=p;
	}
	return ret;
}
	
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	string str;
	cin>>str;
	cout<<longestPalindrome2(str)<<endl;

    system("pause");
}

