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
    int mat[301][301];
	int n, temp, from, to;
	while(cin>>n)
	{
        memset(mat, 0, sizeof(mat));
	
		string str;
		for(int i=0;i<n;i++)
		{
		 	cin>>str;
		 	for(int i=0;i<str.size();i++)
		 			if(str[i]=='-' || str[i]==',')
		 						   str[i]=' ';
	        stringstream ss(str);
	        bool first=true;
	        while(ss>>temp)
	        {
			     //cout<<temp<<" ";
	             if(first==true)
	             {
				  	from=temp;			
	 				first=false;
				 } else
				 {
				   	   mat[from][temp]=1;
		         }
	       }
	       //cout<<endl;
	    }
	    
	    int conns;
	    cin>>conns;
	    cout<<"-----\n";
	    for(int i=0;i<conns;i++)
	    {
		 		queue< vector<int> >Q;
				cin>>from>>to;
				vector<int>path;  
				vector<int>temp_path;
				path.push_back(from);
				Q.push(path);
				int visit[301], upto;
				memset(visit, -1, sizeof(visit));
				visit[from]=0;
				vector<int>res;
				while(!Q.empty())
				{
			         path=Q.front();
			         Q.pop();
			         upto=path[path.size()-1];
			         if(upto==to)
	       			     res=path;
			         for(int i=1;i<=n;i++)
			         {
					  		 if(mat[upto][i]==1 && visit[i]==-1)
					  		 {
			  					   //cout<<upto<<" "<<i<<endl;
						  		   temp_path=path;
						  		   temp_path.push_back(i);
			  					   Q.push(temp_path);
			  					   visit[i]=visit[temp]+1;
	                         }
			         }
			    }
			    if(visit[to]!=-1)
			    {
				 	for(int j=0;j<res.size()-1;j++)
					{
					 	cout<<res[j]<<" ";
					}
					cout<<res[res.size()-1];
					cout<<endl;    
				}
	            else
	                cout<<"connection impossible\n";
		}
	}
	//cout<<str<<endl;	

    system("pause");
}

