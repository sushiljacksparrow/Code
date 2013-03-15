#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int arr[1000001];
	int n, d;
	scanf("%d %d", &n, &d);
	
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
		
	int dp[1000001];
	
	dp[0]=0;
	
	for(int i=1;i<n;i++)
	{
		dp[i]=999999;
		for(int j=0;j<i;j++)
		{
			if(i<=j+arr[j] && dp[j]!=999999)
			{
				dp[i]=dp[j]+1;
				break;
			}
		}
	}
	
	printf("%d\n", dp[n-1]);
	system("pause");
}