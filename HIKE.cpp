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

struct pos
{
       int p1, p2, p3;
 	   int moves;
};
 
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int n;
	while(cin>>n && n!=0)
	{
		pos start;
		pos temp, temp1;
		//start=(pos*)malloc(sizeof(pos*));
	//	int p1, p2, p3;
		cin>>start.p1>>start.p2>>start.p3;
		start.moves=0;
		char color[51][51];
		for(int i=1;i<=n;i++)
		{
		 		for(int j=1;j<=n;j++)
		 		{
				 		cin>>color[i][j];
		        }
		}
		int prevs[51][51][51];
		memset(prevs, -1, sizeof(prevs));
		prevs[start.p1][start.p2][start.p3]=0;
	
		int ans=-1;
		queue<pos>Q;
		Q.push(start);
		//pos * temp1 = (pos*)malloc(sizeof(pos*));
		while(!Q.empty())
		{
		 		temp=Q.front();
		 	//	cout<<"Popped " <<temp.p1<<" "<<temp.p2<<" "<<temp.p3<<endl<<endl;
				Q.pop();
				if((temp.p1==temp.p2) && (temp.p1 == temp.p3))
				{
				    ans=temp.moves;
				 	break;
				}
				
				for(int i=1;i<=n;i++)
				{
				 		if(color[temp.p1][i]==color[temp.p2][temp.p3])
				 		{
						    if(prevs[i][temp.p2][temp.p3]==-1)
						    {
							 	 //pos *temp1=(pos*)malloc(sizeof(pos*));										
				//			     cout<<"jumped "<<temp.p1<<" "<<i<<endl;
							     prevs[i][temp.p2][temp.p3]=0;
							     temp1.p1=i; temp1.p2=temp.p2; temp1.p3=temp.p3;
								 temp1.moves=temp.moves+1; Q.push(temp1);
					//			 cout<<"new stage "<<temp1.p1<<" "<<temp1.p2<<" "<<temp1.p3<<endl;
			                }
	                    }
	                    if(color[temp.p2][i]==color[temp.p1][temp.p3])
				 		{
						    if(prevs[temp.p1][i][temp.p3]==-1)
						    {
							 	 //pos *temp1=(pos*)malloc(sizeof(pos*));										
					    //         cout<<"jumped "<<temp.p2<<" "<<i<<endl;										
							     prevs[temp.p1][i][temp.p3]=0;
							     temp1.p2=i; temp1.p1=temp.p1; temp1.p3=temp.p3;
							     temp1.moves=temp.moves+1; Q.push(temp1);
						//	     cout<<"new stage "<<temp1.p1<<" "<<temp1.p2<<" "<<temp1.p3<<endl;
			                }
			            }
			            if(color[temp.p3][i]==color[temp.p1][temp.p2])
				 		{
						    if(prevs[temp.p1][temp.p2][i]==-1)
						    {
							 	// pos *temp1=(pos*)malloc(sizeof(pos*));										
	                          //   cout<<"jumped "<<temp.p3<<" "<<i<<endl;
							     prevs[temp.p1][temp.p2][i]=0;
							     temp1.p3=i; temp1.p1=temp.p1; temp1.p2=temp.p2;
							     temp1.moves=temp.moves+1; Q.push(temp1);
							//     cout<<"new stage "<<temp1.p1<<" "<<temp1.p2<<" "<<temp1.p3<<endl;
			                }
			            }
			 }
		}
		//cout<<"dasdaius";				 
		if(ans!=-1)
	       cout<<ans<<endl;
	    else
	       cout<<"impossible\n";
   } 	
    system("pause");
}

