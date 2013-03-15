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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int dp[101][101];
	int from, to;
	
	while(cin>>from>>to && from!=0 && to!=0)
	{
	 	 memset(dp, 999999, sizeof(dp));				
	     dp[from][to]=1;
         while(cin>>from>>to && from!=0 && to!=0)
         {
	         dp[from][to]=1;
         }
         for(int i=1;i<=100;i++)
         {
		  		 for(int j=1;j<=100;j++)
		  		 {
				  		 if(i!=j)
				  		 {
				  		    if(dp[i][j]<99999)
				  		 	cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
						 }
			    }
	     }
         for(int i=1;i<=100;i++)
         {
	  		 for(int j=1;j<=100;j++)
	  		 {
	  		    for(int k=1;k<=100;k++)
	  		    {
			 		dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
			    }
	         }
         }
         for(int i=1;i<=100;i++)
         {
		  		 for(int j=1;j<=100;j++)
		  		 {
				  		 if(i!=j)
				  		 {
				  		    if(dp[i][j]<99999)
				  		 	cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
						 }
			    }
	    }
        double count=0.0, sum=0.0;
        for(int i=1;i<=100;i++)
        {
		 		for(int j=1;j<=100;j++)
		 		{
				 		if(dp[i][j]<99999 && i!=j)
				 		{
				 		   sum+=dp[i][j];
				 		   count++;
				        }
			    }
	    }
	   cout<<sum<<" "<<count<<endl;
	   printf("%.3lf\n",sum/count);
    }		 		
    system("pause");
}

