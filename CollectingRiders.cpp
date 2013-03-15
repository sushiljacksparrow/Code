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

int arrx[8]={1, 2, 2, 1, -1, -2, -2, -1};
int arry[8]={2, 1, -1, -2, -2, -1, 1, 2};
class CollectingRiders {
public:
	int minimalMoves(vector <string> board) 
	{
	 	int n=board.size();
	 	int m=board[0].size();
		int moves=-1;
		int dist[11][11];
		for(int sx=0;sx<n;sx++)
		{
		 	for(int sy=0;sy<m;sy++)
	        {
	        	cout<<"For "<<sx<<" "<<sy<<endl;
			  	 //for(int i=0;i<n;i++) for(int j=0;j<m;j++) dist[i][j]=10000;
			  	 fill(dist[0], dist[10], 10000);
				 dist[sx][sy]=0;
				 queue<int>Q;
				 Q.push(sx); Q.push(sy);
				 while(!Q.empty())
				 {
			          int x=Q.front(); Q.pop();
			          int y=Q.front(); Q.pop();
			          int mm=dist[x][y];
			          for(int i=0;i<8;i++)
			          {
			          	  //cout<<x+arrx[i]<<" "<<y+arry[i]<<" "<<dist[x+arrx[i]][y+arry[i]]<<"  "<<n<<" "<<m<<endl;
 		                  if(x+arrx[i] >= 0 && x+arrx[i] < n && y+arry[i] >= 0 && y+arry[i] < m && (dist[x+arrx[i]][y+arry[i]] == 10000))
 		                  {
 		                      //cout<<"inserting " << x+arrx[i]<<" "<<y+arry[i]<<endl;
			                  Q.push(x+arrx[i]);
			                  Q.push(y+arry[i]);
			                  dist[x+arrx[i]][y+arry[i]]=mm+1;
                          }
			          }
			      }
			      
			      int s=0;
			      for(int i=0;i<n;i++)
			      {
		   		     for(int j=0;j<m;j++)
		   		     {
		   		     	if(board[i][j]!='.')
		   		     	{
			  		     	if(dist[i][j]==10000)
			  		        	dist[i][j]=-100000000;
 		                    else
 		                    	s+=dist[i][j]==0 ? 0 : (dist[i][j]-1)/(board[i][j]-'0')+1;
 		                }
					 }
				  }
				  if(s>=0 && (moves<0 || s<moves))
				     moves=s;
			  }
		  }			  
		  return moves;			 		
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
