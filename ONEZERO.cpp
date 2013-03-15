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


#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define ii pair<int,int>
#define vs vector<string>
#define all(v) (v).begin(), (v).end()
#define For(i,x) for(int i=0;i<x;i++)

struct node
{
 	   string num;
 	   int mod;
};

string to_binary(long long num)
{
 	   if(num==0) return "0";
 	   string ret="";
 	   char ch;
 	   while(num!=0)
 	   {
	   		ch=(num%2+'0');
	        ret=ch+ret;
	   		num=num/2;
       }
	   return ret;
}

long long to_long(string str)
{
 	 long long ret=0L, start=1L;
	 int len=str.size();
	 for(int i=len-1;i>=0;i--)
	 {
	  	ret+=(str[i]-'0')*start;
		start=start*2;
     }
	 return ret;
}		
	   	
string bfs(int n)
{
 	queue<node>Q;
 	bool visit[20000];
 	for(int i=0;i<20000;i++)
 			visit[i]=0;
   node temp, temp1;
   temp.num="1";
   temp.mod=1%n;
   Q.push(temp);
   visit[temp.mod]=1;
   while(!Q.empty())
   {
		temp = Q.front();
		//cout<<temp.num<<" "<<temp.mod<<endl;
		//system("pause");
		Q.pop();
		if(temp.mod==0)
		{
		   return temp.num;
        }
        
        temp1.mod=(temp.mod*10)%n;
        if(visit[temp1.mod]==0)
        {
		   visit[temp1.mod]=1;
		   temp1.num=temp.num+"0";
		   Q.push(temp1);
        }
        temp1.mod=(temp.mod*10+1)%n;
        if(visit[temp1.mod]==0)
        {
		   visit[temp1.mod]=1;
		   temp1.num=temp.num+"1";
		   Q.push(temp1);
        }
    }
}
        
        
		   
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int t,n;
	cin>>t;
	while(t--)
	{
	 		  cin>>n;
	 		  if(n==0 || n==1)
 		      {
		   		  cout<<n<<endl;
              } else
              {
	   		      cout<<bfs(n)<<endl;
              }
			 
    }
    system("pause");
}

