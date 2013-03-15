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

enum
{
	MATCH, INSERT, DELETE
};
int dp[100][100];
int s[100][100];

void edit_distance(string p, string t)
{
	int len1=p.length();
	int len2=t.length();
	for(int i=0;i<=len1;i++)
		dp[i][0]=i;
	for(int j=1;j<=len2;j++)
		dp[0][j]=j;
	s[0][0]=-1;
	int opt[3];
	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			int val=0;
			if(p[i-1]!=t[j-1])
				val=1;
			opt[MATCH]=dp[i-1][j-1] + val;
			opt[INSERT]=dp[i][j-1]+1;
			opt[DELETE]=dp[i-1][j]+1;
			
			dp[i][j]=opt[MATCH];
			s[i][j]=MATCH;
			for(int k=INSERT;k<=DELETE;k++)
			{
				if(dp[i][j]>opt[k])
				{
					dp[i][j]=opt[k];
					s[i][j]=k;
				}
			}
		}
	}
	cout<<endl;
	for(int i=0;i<=len1;i++)
	{
		for(int j=0;j<=len2;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[len1][len2]<<endl;
}
	
void reconstruct(string p, string t, int i, int j)
{
	if(s[i][j]==-1)
		return;	
	if(s[i][j]==MATCH)
	{
		reconstruct(p,t,i-1,j-1);
		cout<<p[i];
		return;
	}
	if(s[i][j]==INSERT)
	{
		reconstruct(p,t,i,j-1);
		string temp=""+ p[i];
		t.insert(j, temp);
		return;
	}
	if(s[i][j]==DELETE)
	{
		reconstruct(p,t,i-1,j);
		p.erase(i);
		return;
	}
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	string p, t;
	cin>>p>>t;
	edit_distance(p,t);
	reconstruct(p, t, p.length()-1, t.length()-1);
	cout<<endl;
    system("pause");
}

