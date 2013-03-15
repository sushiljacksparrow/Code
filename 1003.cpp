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

void solve(vector<int>v)
{
	int n=v.size();
	// for(int i=0;i<n;i++)
		// cout<<v[i]<<" ";
	// cout<<"\n\n";
	int dp[n+1][n+1];
	memset(dp, 0, sizeof(dp));
	for(int i=1;i<n;i++)
		dp[i][i+1]=0;
	
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l;i++)
		{
			int j=i+l;
			dp[i][j]=INF;
			for(int k=i+1;k<=j-1;k++)
			{
				int temp=dp[i][k]+dp[k][j]+(v[j-1]-v[i-1]);
				if(temp<dp[i][j])
					dp[i][j]=temp;
			}
		}
	}
	// for(int i=1;i<=n;i++)
	// {
		// for(int j=1;j<=n;j++)
		// {
			// cout<<dp[i][j]<<" ";
		// }
		// cout<<endl;
	// }
	cout<<"The minimum cutting is "<<dp[1][n]<<"."<<endl;
}

int main()
{
	int n,m,c;
	vector<int>v;
	
	while(cin>>n && n!=0)
	{
		v.push_back(0);
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>c;
			v.push_back(c);
		}
		v.push_back(n);
		sort(v.begin(), v.end());
		solve(v);
		v.clear();
	}
	return 0;
}