#include<iostream>

using namespace std;
int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int lcm(int a, int b)
{
	return (a*b)/gcd(a,b);
}
int main()
{
	int sum[1000001];
	for(int i=0;i<=1000000;i++) sum[i]=0;
	int t, n;
	// for(int i=1;i<=1000000;i++)
	// {
		// for(int j=1;j<=i;j++)
		// {
			// sum[i]+=lcm(j,i);
		// }
	// }
	cout<<"done";
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<sum[n]<<" ";
	}
	return 0;
}
	