#include<iostream>

using namespace std;




int main()
{
	int arr[1001];
	int n, m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		scanf("%d", arr[i]);
	
	int dp[m+1]={0};
	dp[0]=1;
	
	for(int i=0;i<n;i++)
		for(int j=m;j>=arr[i];j--)
			dp[j]|=dp[j-arr[i]];
	
	cout<<dp[m]<<endl;
	
	system("pause");
}