#include<iostream>

using namespace std;

int main()
{
	int arr[100];
	int n, sum=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
		sum+=arr[i];
	}
	
	int dp[sum+1]={0};
	dp[0]=1;
	for(int i=0;i<n;i++)
		for(int j=sum;j>=arr[i];j++)
			dp[j]|=dp[j-arr[i]];
	int org = sum;
	sum/=2;
	int dist=0;
	for(;sum-dis>=0;dist++)
		if(dp[sum-dis]||dp[sum+dist])
			break;
	printf("%d %d\n", sum-dist, orf-sum+dist);
	system("pause");
}