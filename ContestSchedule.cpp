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

// int len;
double solve(vector<string>vst)
{
	int len=vst.size();
	int match[50][3];
	stringstream ss (stringstream::in | stringstream::out);
	for(int i=0;i<len;i++)
	{
		ss<<vst[i];
		ss>>match[i][0]>>match[i][1]>>match[i][2];
	}
		
	vector<int>time;
	for(int i=0;i<len;i++)
	{
		time.push_back(match[i][0]);
		time.push_back(match[i][1]);
	}
	sort(time.begin(), time.end());
	// for(int i=0;i<2*len;i++) cout<<time[i]<<" ";
	int dp[2*len];
	dp[2*len-1]=0;
	for(int i=2*len-2;i>=0;i--)
	{
		dp[i]=dp[i+1];
		for(int j=0;j<len;j++)
		{
			if(match[j][0]==time[i])
			{
				int k=i+1;
				while(k<2*len-1)
				{
					if(match[j][1]==time[k])
						break;
					k++;
				}
				dp[i]=max(dp[i], match[j][2]+dp[k]);
			}
		}
	}
	for(int i=0;i<2*len;i++)
	{
		cout<<time[i]<<" "<<dp[i]<<endl;
	}
	return ((double)dp[0])/100.0;
}
	
		
	
// }
		
	
int main()
{
	cout<<solve(match)<<endl;
	return 0;
}