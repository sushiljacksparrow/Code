#include<iostream>

using namespace std;

int main()
{
	int n, c;
	cin>>n>>c;
	int arr[100][2];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i][0]>>arr[i][1];
	}
	
	int dp[100][100];
	for(int i=0;i<=c;i++)
		dp[0][i]=0;
	for(int i=0;i<n;i++)
	{
		dp[i][0]=0;
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=c;j++)
		{
			if(j-arr[i][0]>=0)
				dp[i][j]=max(dp[i-1][j], dp[i-1][j-arr[i][0]]+arr[i][1]);
		}
	}
	
	int ans=0;
	for(int i=0;i<=c;i++)
		ans=max(ans, arr[n-1][i])
	cout<<ans<<endl;
}