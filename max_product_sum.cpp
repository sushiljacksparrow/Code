#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int arr[10];
	for(int i=0;i<10;i++)
		cin>>arr[i];

	int max_end_here=1, min_end_here=1;
	int ret=-99999;
	for(int i=0;i<10;i++)
	{
		if(arr[i]>0)
		{
			max_end_here=max_end_here*arr[i];
			min_end_here=(min_end_here*arr[i], 1);
		} else if(arr[i]==0)
		{
			max_end_here=1;
			min_end_here=1;
		} else
		{
			int temp=max_end_here;
			max_end_here=max(min_end_here*arr[i],1);
			min_end_here=temp*arr[i];
		}

	
		if(max_end_here > ret)
			ret=max_end_here;
	}

	cout<<ret<<endl;
}
