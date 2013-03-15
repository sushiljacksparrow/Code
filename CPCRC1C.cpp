#include<iostream>

using namespace std;

int main()
{
	int a, int b;
	while(cin>>a>>b && a!= -1 && b!= -1)
	{
		int digs=log(n);
		long long int i=10;
		int ind=1;
		int sum=0;
		while(ind<=digs)
		{
			int num=a%i;
			