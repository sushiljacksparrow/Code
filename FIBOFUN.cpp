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
void multipl(int F[2][2], int M[2][2]);
void power(int F[2][2], int n);

int fib(int n, int a, int b)
{
	if(n==0)
		return a;
	int F[2][2]={{1,1},{1,0}};
	power(F, n-1);
	return F[0][0]*b+F[0][1]*a;
}

void power(int F[2][2], int n)
{
	if(n==0 || n==1)
		return;
	int M[2][2]={{1,1,},{1,0}};
	power(F, n/2);
	multipl(F, F);
	if(n%2!=0)
		multipl(F,M);
}

void multipl(int F[2][2], int M[2][2])
{
	int x=F[0][0]*M[0][1]+F[0][1]*M[1][0];
	int y=F[0][0]*M[0][1]+F[0][1]*M[1][1];
	int z=F[1][0]*M[0][0]+F[1][1]*M[1][0];
	int w=F[1][0]*M[0][1]+F[1][1]*M[1][1];
	
	F[0][0]=x;
	F[0][1]=y;
	F[1][0]=z;
	F[1][1]=w;
}

int main()
{
	int a, b, n, m, t;
	scanf("%d", &t);
	while(t--)
	{
		// cout<<"wadw";
		scanf("%d %d, %d %d", &a, &b, &n, &m);
		int sum=fib(n+1, a, b)-b;
		// sum=sum;
		printf("%d\n", sum);
	}
	return 0;
}