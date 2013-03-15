#include<iostream>
#include <math.h>

using namespace std;

int choose(int n, int k)
{
	if(k<0 || k>n)
		return 0;
	if(k>n-k)
		k=n-k;
		
	int c=1;
	for(int i=0;i<k;i++)
	{
		c*=(n-i);
		c/=(i+1);
	}
	return c;
}

int main()
{
	int m, n, t, p;
	cin>>m>>n>>t>>p;
	double required_wins = ceil(p/t);
	
	int people = p;
	int rest = m-p;
	int draws = n;
	double loss = 0.0;
	
	for(int i=0;i<required_wins;i++)
		loss+=(double)choose(rest, draws-i)*(double)choose(people, i);
	
	double total = choose(m, n);
	cout<<1.0-loss/total<<endl;
	system("pause");
}
