#include<iostream>
#include<algorithm>

using namespace std;

int solve(int arr[], int n)
{
	int global_max = 1;
	int max_so_far = 1;
	int min_so_far = 1;

	for(int i=0;i<n;i++)
	{
		if(arr[i]>0)
		{
			max_so_far = max_so_far * arr[i];
			min_so_far = max(min_so_far, 1);
		} else if(arr[i] == 0)
		{
			max_so_far = 1;
			min_so_far = 1;
		} else
		{
			int t = max_so_far;
			max_so_far = max(min_so_far * arr[i], 1);
			min_so_far = t * arr[i];
		}

		if(global_max < max_so_far)
			global_max = max_so_far;
	}
	return global_max;
}

int main()
{
	int arr[]={6, -3, -10, 0, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<solve(arr, n)<<endl;
	return 0;
}