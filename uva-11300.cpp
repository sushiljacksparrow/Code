#include <stdio.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAXN 1000001
#define u64 unsigned long long
#define i64 long long
#define rep(i,n) for(i=0;i<(n);i++)
#define min(a,b) (((a)<(b))?(a):(b))
#define mabs(x) (((x)<0)?(-x):(x))

int n;
u64 a[MAXN];
i64 A[MAXN];
u64 sum, per;

int main()
{
	int i;
	u64 res;
	i64 mid;
	while(scanf("%d", &n)==1)
	{
		sum=0;
		rep(i,n)
		{
			scanf("%llu", &a[i]);
			sum+=a[i];
		}
		per = sum/n;
		rep(i,n)
			A[i]=per-a[i];
		for(i=n-2;i>0;i--)
			A[i]=A[i+1]+A[i];
		A[0]=0;
		sort(A, A+n);
		mid=(A[n/2]+A[(n-1)/2])/2;
		
		res=0;
		rep(i,n)
		{
			A[i]-=mid;
			res+=mabs(A[i]);
		}
		printf("%llu\n", res);
	}		
	system("pause");
}
