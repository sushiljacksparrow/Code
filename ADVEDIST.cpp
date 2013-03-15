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


static const int MAX_LEN = 1000;
 
char a[MAX_LEN+2], b[MAX_LEN+2];
int aLen, bLen;
 

void readStrings()
{
	scanf("%s %s", a+1, b+1);
	aLen=strlen(a+1);
	bLen=strlen(b+1);
}

void distance()
{
	int INF = aLen+bLen;
	int dp[aLen+2][bLen+2];
	dp[0][0]=INF;
	for(int i=0;i<=aLen;i++)
		dp[i+1][1]=i, dp[i+1][0]=INF;
	for(int i=0;i<=bLen;i++)
		dp[1][i+1]=i, dp[0][i+1]=INF;
	int cost=0;
	int C='z'+1;
	int DA[C];
	for(int d=0;d<C;d++)
		DA[d]=0;
		
	for(int i=1;i<=aLen;i++)
	{
		int DB=0;
		for(int j=1;j<=bLen;j++)
		{
			int i1=DA[b[j-1]];
			int j1=DB;
			int d=(a[i-1]==b[j-1])?0:1;
			
			if(d==0)	DB=j;
			
			dp[i+1][j+1]=min(dp[i][j]+d, dp[i+1][j]+1);
			dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j+1]+1);
			dp[i+1][j+1]=min(dp[i+1][j+1], dp[i1][j1]+(i-i1-1)+1+(j-j1-1));
		}
		DA[a[i-1]]=i;
	}
	printf("%d\n", dp[aLen+1][bLen+1]);
}
	
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	while(1)
	{
		readStrings();
		if(a[1]=='*')
			break;
		distance();	
	}	

    system("pause");
}


