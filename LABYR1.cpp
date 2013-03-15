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

char arr[1001][1001];
int maxi, px, py;
int test, r, c;
int dir[4][2]={{1,0}, {-1,0}, {0,1}, {0,-1}};

void dfs(int x, int y, bool flag[1001][1001], int len)
{
	if(len>maxi)
	{
		px=x;
		py=y;
		maxi=len;
	}
	
	flag[x][y]=true;
	for(int i=0;i<4;i++)
	{
		if(x+dir[i][0]<r && x+dir[i][0]>=0 && y+dir[i][1]<c && y+dir[i][1]>=0 && arr[x+dir[i][0]][y+dir[i][1]]=='.')
		{
			if(flag[x+dir[i][0]][y+dir[i][1]]==false)
			{
				dfs(x+dir[i][0], y+dir[i][1], flag, len+1);
			}
		}
	}
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

	cin>>test;
	while(test--)
	{
		cin>>c>>r;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>arr[i][j];
			}
		}
		bool flag[1001][1001];
		int sx,sy;
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				if(arr[i][j]=='.')
				{
					sx=i;
					sy=j;
				}
			}
		}
		memset(flag, false, sizeof(flag));
		maxi=0;
		dfs(sx, sy, flag, 0);	
//		cout<<px<<" "<<py<<endl;
		maxi=0;
		memset(flag, false, sizeof(flag));
		dfs(px, py, flag, 0);
		
		cout<<"Maximum rope length is "<<maxi<<"."<<endl;
	}
    system("pause");
}

