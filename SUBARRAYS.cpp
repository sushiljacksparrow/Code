#include<iostream>
#include<stdio.h>

using namespace std;

int arr[1000001];

int main()
{
	int n,k;
	scanf("%d", &n);
	
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	scanf("%d", &k);
	
	int m=arr[0];
	for(int i=1;i<k;i++)
		if(arr[i]>m)
            m=arr[i];
	
	if(k!=n)
		printf("%d ", m);
	else
		printf("%d", m);
	
	for(int i=k;i<n;i++)
	{
		if(arr[i-k]==m) // case when the outgoing element was maximum
		{
			m=-1;
			for(int j=i-k+1;j<=i;j++)
				if(arr[j]>m)
					m=arr[j];
			if(i!=n)
				printf("%d ", m);
			else
				printf("%d", m);
		} else
		{
			if(arr[i]>m) // case when incoming element is maximum
			{
				m=arr[i];
				if(i!=n)
					printf("%d ", m);
				else
					printf("%d", m);
			} else
			{
				if(i!=n)
					printf("%d ", m);
				else
					printf("%d", m);
			}
		}
	}
	printf("\n");
	system("pause");
}
				