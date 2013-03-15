#include<iostream>

using namespace std;

int main()
{
	int arr[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int L[n];
	for(int i=0;i<n;i++) L[i]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			{
				L[i]=L[i]>L[j]+1 ? L[i] : L[j]+1;
			}
		}
	}
	
	int ans=0;
	for(int i=0;i<n;i++)
		ans= ans>L[i]? ans: L[i];
	
	cout<<ans<<endl;
}