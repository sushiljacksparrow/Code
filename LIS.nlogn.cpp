#include<iostream>
#include<algorithm>

using namespace std;

int search(int arr[], int beg, int end, int key)
{
	int mid;
	while(end-beg>1)
	{
		mid = (end+beg)/2;
		(arr[mid]>=key ? end : beg) = mid;
	}
	return end;
}

int solve(int arr[], int n)
{
	int temp[n];
	temp[0]=arr[0];
	int len=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i] < temp[0])
			temp[0] = arr[i];
		else if(arr[i] > temp[len-1])
		{
			temp[len++]=arr[i];
		} else
		{
			temp[search(temp, -1, len-1, arr[i])] = arr[i];
		}
	}

	int ret = 1;
	for(int i=0;i<n;i++)
		ret = max(ret, temp[i]);
	return ret;
}

int main()
{
	int A[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    	int n = sizeof(A)/sizeof(A[0]);
 
    	printf("Length of Longest Increasing Subsequence is %d\n",solve(A, n));
 
    return 0;
}