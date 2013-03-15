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

int main()
{
	string a, b;
	while(cin>>a>>b)
	{
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int la=a.size();
		int	lb=b.size();
		int i=0, j=0;
		string ret="";
		while(i<la && j<lb)
		{
			if(a[i]==b[j])
			{
				ret+=a[i];
				i++;
				j++;
			} else if(a[i]>b[j])
			{
				j++;
			} else if(b[j]>a[i])
			{
				i++;
			}
		}
		cout<<ret<<endl;
	}
	return 0;
}