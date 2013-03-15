#include<iostream>

using namespace std;

bool solve(int n)
{
	bool dp[n+1];
	memset(dp, false, sizeof(dp));
	dp[0]=true;
	int arr[3]={6,9,20};
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++)
			if(i>=arr[j])
				dp[i]|=dp[i-arr[j]];
	return dp[n];
}
int main()
{
	int n;
	while(cin>>n)
		cout<<solve(n)<<endl;
	system("pause");
}
