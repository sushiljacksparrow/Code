#include<iostream>

using namespace std;

int arr[1000001];
int main()
{
	int test;
	cin>>test;
	int ind=1;
	while(test--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
			
		int ret=0, res=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]>0)
			{
				res+=arr[i];
			} else
			{
				if(res+arr[i]>0)
				{
					res+=arr[i];
				} else
				{
					ret+=((-1)*(arr[i]+res));
					res=1;
				}
			}
		}
		printf("Scenario #%d: %d\n", ind, ret);
		ind++;
	}
}
		