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

using namespace std;//,14930352
int arr[35]={0,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465};
int bs(int k)
{
	int s=0, e=34, mid;
	while(e>s)
	{
		// cout<<s<<" "<<e<<" "<<arr[s]<<" "<<arr[e]<<endl;
		mid=(e+s)/2;
		if(arr[mid]==k)
			return mid;
		if(e-s==1)
		{
			if(k-arr[s]<arr[e]-k)
				return s;
			else
				return e;
		}
		if(arr[mid]>k)
			e=mid;
		else
			s=mid;
	}
}

int coun[100001];
int main()
{
	int t, n;
	// cout<<arr[bs(4)]<<endl;
	// system("pause");
	while(1)
	{
		scanf("%d", &t);
		if(t==0)
			break;
		for(int i=0;i<t;i++)
		{
			scanf("%d", &n);
			coun[i]=arr[bs(n)];
		}
		sort(coun, coun+t);
		cout<<coun[0];
		for(int i=1;i<t;i++)
			printf(" %d", coun[i]);
			// cout<<" "<<coun[i];
		cout<<endl;
	}
	return 0;
}