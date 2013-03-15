#include<iostream>
#include<algorithm>

using namespace std;

int solve(int arr[], int n)
{
	int dp[n];
	dp[0]=0;
	for(int i=1;i<n;i++)
	{
		dp[i]=INT_MAX;
		for(int j=0;j<i;j++)
		{
			if(j+arr[j]>=i && arr[j]!=INT_MAX)
				dp[i]=min(dp[i], dp[j]+1);
		}
	}
	return dp[n-1];
}
int main()
{
}