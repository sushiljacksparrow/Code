#include<iostream>

using namespace std;

int main()
{
	int arr[]={1,2,3,5,8,12,15,21,37,56};
	int n= sizeof(arr)/sizeof(arr[0]);
	
	int s;
	cin>>s;
	int dp[s+1];
	// memset(dp, 999, sizeof(dp));
	for(int i=1;i<=s;i++)
		dp[i]=999;
	dp[0]=0;
	
	for(int i=1;i<=s;i++)
	{
		for(int j=0;j<n;j++)
			if(i-arr[j]>=0)
				dp[i]=min(dp[i], dp[i-arr[j]]+1);
	}			
	cout<<dp[s]<<endl;
	system("pause");
}
