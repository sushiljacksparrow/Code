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

 	 int mod[20000];
 	  	 int pos[20001];
 	  	  	 char res[20001];
void bfs(int n)
{



 	 
 	 
 	 queue<int>Q;
 	 Q.push(1);
 	 pos[1]=-1;
 	 int cur, next;
 	 while(!Q.empty())
 	 {
	  				  
 	      cur=Q.front();
 	      
		  Q.pop();
		  next=(cur*10)%n;
	//	  cout<<next<<" ";
		  if(next==0)
		  {
		   	  pos[next]=cur;
			  res[next]='0';
			  break;
		  }
		  if(mod[next]==0)
		  {
		   	  mod[next]=1;
			  pos[next]=cur;
			  res[next]='0';
			  Q.push(next);
		  }
		  next=(cur*10+1)%n;
		  //cout<<next<<endl;
		  if(next==0)
		  {
		   	  pos[next]=cur;
			  res[next]='1';
			  break;
		  }
		  if(mod[next]==0)
		  {
		   	  mod[next]=1;
			  res[next]='1';
			  pos[next]=cur;
			  Q.push(next);
		  }
	  }
	  //for(int i=0;i<10;i++)
	  //cout<<pos[i]<<" ";
	  string str="";
	  int ind=0;
	  while(1)
	  {
	   		//cout<<str<<endl;  
	   	//	cout<<ind<<" "<<str<<endl;
	   		//system("pause");
	   	   if(pos[ind]==-1) break;
		   str=res[ind]+str;
		   ind=pos[ind];
     }
	 str="1"+str;
	 cout<<str<<endl;
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
 	    memset(mod,0,sizeof(mod));
 	    if(n==1) {cout<<"1"<<endl;continue;}
 	    mod[1]=1;
 	    bfs(n);
	}

    system("pause");
}

