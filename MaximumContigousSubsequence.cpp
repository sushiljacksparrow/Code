#include<iostream>

using namespace std;

int main()
{
	int arr[5]={1, 3, 10, -10, 15};
	int M[5];
	M[0]=arr[0];
	for(int i=1;i<5;i++)
	{
		M[i]=M[i-1]+arr[i] >= arr[i] ? M[i-1]+arr[i] : arr[i];
	}
	int ret=-999;
	for(int i=0;i<5;i++)
		ret= ret > M[i] ? ret : M[i];
	cout<<ret<<endl;
}