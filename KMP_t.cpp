#include<iostream>

using namespace std;

// largest prefix suffix which is also a prefix

// ababc
// a 0
// b 0
// c 1
// b 
void failure_func(int arr[], string p)
{
	int m=p.size();
	arr[0]=0;
	int i=1;
	int len=0;
	while(i<m)
	{
		if(p[i]==p[len])
		{
			len++;
			arr[i]=len;
			i++;
		} else 
		{
			if(len!=0)
			{
				len=arr[len-1];
			} else
			{
				arr[i]=0;
				i++;
			}
		}
	}
}
	
int main()
{
	string t, p;
	cin>>p>>t;
	
	int n= p.size(), m = t.size();
	int arr[n+1];
	failure_func(arr, p);
	
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

		int i=0, j=0;
		while(j<m)
		{
			if(p[i]==t[j])
			{
				i++;
				j++;
			}
			if(i==n)
			{
					cout<<"pattern found at "<<j-i<<endl;
					i=arr[i-1];
			} else if(p[i]!=t[j])
			{
				if(i)
					i=arr[i];
				else
					j=j+1;
			}
		}

	
	system("pause");
}
