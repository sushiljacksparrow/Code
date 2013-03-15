#include<iostream>

using namespace std;

int main()
{
	int test;
	unsigned long long n, res;
	cin>>test;
	while(test--)
	{
		res=1;
		cin>>n;
		int count=0;
		while(n>res)
		{
			res = res<<1;
			count++;
		}
		cout<<count<<" "<<res<<endl;
	}
}