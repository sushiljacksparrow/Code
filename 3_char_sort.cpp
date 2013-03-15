#include<iostream>

using namespace std;

int main()
{
	int arr[]={0,1,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	int left = 0, mid = 0, right = n-1;
	while(mid<right)
	{
		// cout<<left<<" "<<mid<<" "<<right<<endl;
		if(arr[mid]==0)
		{
			swap(arr[left], arr[mid]);
			mid++;
			left++;
		} else if(arr[mid]==1)
		{
			mid++;
		} else if(arr[mid]==2)
		{
			swap(arr[mid], arr[right]);
			right--;
			mid++;
		}
	}
	
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	system("pause");
}
