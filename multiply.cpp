#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

string multiply(char a[], char b[])
{
	int la=strlen(a);
	int lb=strlen(b);
	char c[la+lb];
	int s=la+lb-1;
	
	for(int i=la-1;i>=0;i--)
	{
		int carry=0;
		int shift=s;
		for(int j=lb-1;j>=0;j--)
		{
			int t=a[i]*b[j];
			int s=t+c[shift]+carry;
			c[shift]=s%10;
			carry=s/10;
			shift--;
		}
		c[shift]+=carry;
		s--;
	}
	return c;
}	

int main()
{
	char a[10], b[10];
	cin>>a>>b;
	cout<<multiply(a,b)<<endl;
	system("pause");
}
