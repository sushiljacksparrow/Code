#include<iostream>

using namespace std;


int find_candidate(int arr[], int N)
{
	int index = 0, count = 1;
	for(int i=1;i<N;i++)
	{
		if(arr[i]==arr[index])
			count++;
		else
			count--;
		if(count==0)
		{
			index=i;
			count=1;
		}
	}
	return arr[index];
}

bool isMajority(int arr[], int N, int cand)
{
	int count = 0;
	for(int i=0;i<N;i++)
	{
		if(arr[i]==cand)
			count++;
		
	}
	if(count>N/2)
		return true;
	else
		return false;
}

void find_majority(int arr[], int N)
{
		int cand = find_candidate(arr, N);
		if(isMajority(arr, N, cand))
			cout<<cand<<endl;
		else
			cout<<-1<<endl;
}
int main()
{
	int arr[]={1, 2, 3, 4, 1, 4,4,4,4,4,4,4,4,4,4,2, 1, 1, 1, 1};
	find_majority(arr, sizeof(arr)/sizeof(arr[0]));
	system("pause");
}
