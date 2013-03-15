#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>

#include <vector>
#include <cstdio>
#include <cctype>
#include <numeric>
#include <utility>

#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <complex>
#include <iostream>
#include <algorithm>
#include <functional>
template<class T> inline int size(const T&c) { return c.size(); }
#define all(x) (x).begin(),(x).end()
#define vs vector <string>
#define vi vector <int>
#define vvi vector < vi >
#define p(X) push_back((X))

#define fir(i,j,n) for(int (i)=(j);(i)<(n);(i)++)
#define fire(i,j,n) for(int (i)=(j);(i)<=(n);(i)++)
#define firr(i,j,n) for(int (i)=(j);(i)>(n);(i)--)
#define firre(i,j,n) for(int (i)=(j);(i)>=(n);(i)--)
#define tr(v,it) for(typeof(v.begin()) it=v.begin();it!=v.end();it++)

#define srt(v) sort((v).begin(),(v).end())
#define srtc(v) sort(v.begin(),v.end(),cmp)

#define _bc(i) __builtin_popcount(i)
#define INF 0x3f3f3f3f
#define ipow(a,b) (int)pow((double)a,(double)b)
#define fill(a,b) memset(a,b,sizeof(a))
#define maxr(num,a,b) max_element(num.begin()+a,num.begin()+b);
#define minr(num,a,b) min_element(num.begin()+a,num.begin()++b)
#define maxi(v) max_element(all(v))
#define mini(v) min_element(all(v))

using namespace std;
int dp[2001][2001];
	
int main()
{
	
	string s1, s2;
	int test;
	cin>>test;
	while(test--)
	{
		cin>>s1>>s2;
		int l1=s1.size(), l2=s2.size();
		dp[0][0]=0;
		for(int i=1;i<=l1;i++) dp[i][0]=i;
		for(int i=1;i<=l2;i++) dp[0][i]=i;
		
		for(int i=1;i<=l1;i++)
		{
			for(int j=1;j<=l2;j++)
			{
				int val=0;
				if(s1[i-1]!=s2[j-1])
					val=1;
				int temp=min(dp[i-1][j]+1, dp[i][j-1]+1);
				dp[i][j]=min(temp, dp[i-1][j-1]+val);
			}
		}
		cout<<dp[l1][l2]<<endl;
	}
		
	return 0;
}
		
	
	
	
	