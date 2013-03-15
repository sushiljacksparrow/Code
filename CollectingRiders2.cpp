#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <queue>
 
using namespace std;
 
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
 
class CollectingRiders {
public:
  int minimalMoves(vector <string> board)
  {
	int n=board.size();int m=board[0].size();int ret=INT_MAX;
	int dp[10][10];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			memset(dp, INT_MAX, sizeof(dp));
			queue<int>qx;queue<int>qy;
			qx.push(i);qy.push(j);
			while(!qx.empty())
			{
				int tx=qx.front();   qx.pop();
				int ty=qy.front();	 qy.pop();
				int mm = dp[tx][ty];
				for(int k=0;k<8;k++)
					if(tx+dx[k]>=0 && tx+dx[k]<n && ty+dy[k]>=0 && ty+dy[k]<m && dp[tx+dx[k]][ty+dy[k]]!=INT_MAX)
					{
						qx.push(tx+dx[k]);
						qy.push(ty+dy[k]);
						dp[tx+dx[k]][ty+dy[k]]=mm+1;
					}
			}
			
			int s=0;
			for(int r=0;r<n;r++)
				for(int c=0;c<m;c++)
					if(board[r][c]!='.')
					{
						if(dp[r][c]==INT_MAX)
							s=-10000000;
						else
							s+= (dp[r][c]==0) ? 0 : (dp[r][c]-1)/(board[c][c]-'0')+1;
					}
			if(s>=0 && (ret<0 || s<ret))
				ret=s;
		}
	return ret;
  }
};