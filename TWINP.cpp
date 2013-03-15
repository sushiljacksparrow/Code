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

#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>

#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <set>

#include <stack>
#include <string>
#include <utility>

#include <vector>

using namespace std;

#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define ii pair<int,int>
#define vs vector<string>
#define all(v) (v).begin(), (v).end()
#define For(i,x) for(int i=0;i<x;i++)


void sieve(int N)
{
 	 bool primes[N+1];
	 for(int i=0;i<=N;i++)
	 {
		primes[i]=true;
	 }
	 int s = sqrt(N);
	 for(int i=2;i<=s;i++)
	 {
		if(primes[i]==true)
		{
			//cout<<i<<" ";
			for(int j=i*2;j<=N;j+=i)
			{
				primes[j]=false;
			}
		}
	 }
	 for(int i=2;i<=N;i++)
	 {
		if(primes[i])
		{
			cout<<i<<" ";
		}
	}
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	sieve(1000000);
	
    system("pause");
}

