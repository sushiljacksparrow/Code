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
int pos[100+1][100+1];
void print(int i, int j)
{
	if(i==j)
	{
		cout<<i<<" ";
		return;
	} else
	{
		cout<<" ( ";
		print(i, pos[i][j]);
		print(pos[i][j]+1,j);
		cout<<" ) ";
	}
}
void matric_mult(vector<int>p)
{
	int n=p.size()-1;  
	int dp[n+1][n+1];
	
	for(int i=1;i<=n;i++)
		dp[i][i]=0;
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			dp[i][j]=INF;
			for(int k=i;k<=j-1;k++)
			{
				int temp=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
				if(temp<dp[i][j])
				{
					dp[i][j]=temp;
					pos[i][j]=k;
				}
			}
		}
	}
	cout<<dp[1][n]<<endl;
	print(1,n);
}

int main()
{
	vector<int>p;
	int mat, n;
	cin>>mat;
	for(int i=0;i<=mat;i++)
	{
		cin>>n;
		p.push_back(n);
	}
	matric_mult(p);
}