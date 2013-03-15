#include<iostream>

using namespace std;

int solve(int arr[], int n)
{
	int s = 0;
	for(int i=0;i<n;i++)
		s+=arr[i];
	
	int dp[n][s+1];
	for(int i=0;i<n;i++)
		dp[i][0]=1;
	for(int i=1;i<=sum;i++)
		dp[0][i]=0;
	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=arr[i])
				dp[i][j]=dp[i][j] || dp[i-1][j-arr[i]];
		}
	}
	int sum = s;
	s = s/2;
	if(arr[n-1][s])
		return 0;
	for(int i=0;i<s;i++)
		if(dp[n-1][s-i])
			return sum  - (s - i);
		else if(dp[n-1][s+i])
			return sum - (s + i);
}
		
	
	
int main()
{
}