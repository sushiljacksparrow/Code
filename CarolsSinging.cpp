#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class CarolsSinging {
public:
	int choose(vector <string> lyrics) 
	{
	 	int res=1000;
		int masks[11];
		int carols=lyrics.size();
		for(int i=0;i<lyrics.size();i++)
		{
		 	 for(int j=0;j<lyrics[0].size();j++)
			 {
			  		 if(lyrics[i][j]=='Y')
					 {
					  		masks[i]=1;
			         } else
					 {
					   	   	masks[i]=1;
			         }
			 }
	   }
	   
	   for(int m=0; m< 1<<carols.size();m++)
	   {
	   		   boolean ok = true;
			   for(int i=0;i<lyrics.size();i++)
			   {
			   		   if(masks[i] & m==0)
						  ok=false;
		       }
			   if(ok && __builtin_popcount(m) < res)
			   		 res=__builtin_popcount(m);
	   }
	   return res;	  	  	
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
