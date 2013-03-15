/*Sushil Kumar Singh */
#include <cassert>
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
#include <ext/numeric>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/algorithm>

using namespace std;
using namespace __gnu_cxx;

#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define ii pair<int,int>
#define vs vector<string>
#define all(v) (v).begin(), (v).end()
#define For(i,x) for(int i=0;i<x;i++)

int prime[100000];
vector<int>actual_primes;
void primes()
{
 	 memset(prime, true, sizeof(prime));		 
 	 prime[0]=false; prime[1]=false; prime[2]=true;
 	 int n=100000;
 	 for(int i=3;i<n;i++)
 	 {
	  	if(prime[i])
	    {
		 	for(int j=i+i;j<=n;j+=i)
					prime[j]=false;
        }
     }
	 for(int i=1000;i<10000;i++)
	 		 if(prime[i])
			  {
			   			 //cout<<i<<" ";
						 actual_primes.push_back(i);
	          }
} 			 
bool dist(int n, int m)
{
 	 //cout<<n<<" "<<m;
 	 int count=0;
 	 for(int i=0;i<4;i++)
 	 {
	  	count+=(n%10 == m%10)?0 : 1;
		 n/=10; m/=10;
     }
     //cout<<count<<endl;
     //cout<<" "<<count<<endl;
     //system("pause");
	 return (count==1);
}
 	 //return ((n%10 != m%10) + (n%100 != m%100) + (n%1000 != m%1000) + (n%10000 != m%10000))==1;
//}		 	  	 
int len;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	bool visit[10000];
	primes();
	len=actual_primes.size();
	int n,m,test;
	cin>>test;
	pair<int, int>new_pair;
	while(test--)
	{
	 	memset(visit, false, sizeof(visit));		 
	 	cin>>n>>m;
	 	//cout<<dist(n,m)<<endl;
	 	//system("pause");
        queue< pair<int, int> > Q;
		pair<int, int> p;
		p.first=n;
		p.second=0;
		Q.push(p);
		visit[n]=true;   // just make it non-prime
		int res=-1;
		while(!Q.empty())
		{
			 
		 	int temp=Q.front().first;
		 	//cout<<" \n from "<<temp<<" ";
			int step=Q.front().second;
			Q.pop();
			if(temp==m)
			{
			 	res=step;
				break;
			} 	   
			for(int i=0;i<len;i++)
			{
			 		
			 	if(visit[actual_primes[i]] == false && dist(temp, actual_primes[i]))
		        {
				 	//cout<<actual_primes[i]<<" ";					    
				  	 new_pair.first=actual_primes[i]; new_pair.second=step+1;
					 Q.push(new_pair);
					 visit[actual_primes[i]]=true;
		        }
			}
		//	system("pause");				   	
		}
		if(res!=-1)
				   cout<<res<<endl;
		else
			cout<<"Impossible\n";				 
	 }		
    system("pause");
}

