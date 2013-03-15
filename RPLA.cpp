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
int relation[10000][2];
int finish[1001];
int visit[1001];
int n, r, from, to;
void dfs(int node)
{
	int t;
	stack<int>s;
	s.push(node);
	int time=1;
	visit[node]=2;
	while(!s.empty())
	{
		t=s.top();
		s.pop();
		// cout<<t<<" ";
		for(int i=0;i<r;i++)
		{
			if(relation[i][1]==t && visit[relation[i][0]]<2)
			{
				visit[relation[i][0]]=1;
				s.push(relation[i][0]);
				time++;
			}
		}
		cout<<t<<" ";
		visit[t]=2;
		finish[t]=++time;
	}
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<i<<" "<<finish[i]<<endl;
}
				
int main()
{
	while(cin>>n>>r)
	{
		for(int i=0;i<r;i++)
		{
			cin>>to>>from;
			relation[i][0]=to;
			relation[i][1]=from;
		}
		memset(finish, -1, sizeof(finish));
		memset(visit, 0, sizeof(visit));
		for(int i=0;i<n;i++)
		{
			if(visit[i]==0)
				dfs(i);
		}
	}
	return 0;
}