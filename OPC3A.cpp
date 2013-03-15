#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

typedef unsigned long long ll;
ll g[1000001];
ll M=ll(1000000007);

ll modpow(int base,ll e)
{
   long long b=base,res=1;
   while(e>0)
   {
      if(e & 1)
      {
         res = res%M * b%M;
      }
      b = b%M * b%M;
      e /= 2;
   }
   return res;
}

void fib()
{
	g[0]=1;
	g[1]=2;
	int ind=2;
	while(ind<1000001)
	{
		g[ind]= (g[ind-2] * g[ind-1])%M;
		ind++;
	}		
}
int main()
{
	int n, test;
	fib();
	
	cin>>test;
	while(test--)
	{
		cin>>n;
		cout<<g[n]<<endl;
	}
	return 0;
}