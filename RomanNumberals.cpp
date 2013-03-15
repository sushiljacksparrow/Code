#include<iostream>

using namespace std;

int main()
{
	string str;
	string rome="IVXLCDM";
	int values[7] = {1,5,10,50,100,500,1000};
	int arr[100];
	while(cin>>str)
	{
		int n=str.size();
		for(int i=0;i<n;i++)
			arr[i]=values[rome.find(str[i])];
		int k=arr[n-1];
		for(int i=n-1;i>0;i--)
			if(arr[i]>arr[i-1])
				k=k-arr[i-1];
			else
				k=k+arr[i-1];
		cout<<k<<endl;
	}
	
	system("pause");
}
