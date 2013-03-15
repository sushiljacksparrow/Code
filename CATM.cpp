/*Sushil Kumar Singh */
/* http://www.spoj.pl/problems/CATM/ */
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

int arr[4][2]={{1,0}, {-1,0}, {0,1}, {0, -1}};
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int n,m;
	bool visit[3][102][102];
	cin>>n>>m;
	memset(visit, false, sizeof(visit));
	queue< pair<int, int> >QM, QC1, QC2;
	pair<int, int>p, pm, pc1, pc2;
	int x, y;
	cin>>p.first>>p.second; QM.push(p); visit[0][p.first][p.second]=true;
	cin>>p.first>>p.second; QC1.push(p); visit[1][p.first][p.second]=true;
	cin>>p.first>>p.second; QC2.push(p); visit[2][p.first][p.second]=true;
	
	int escape=1;
	int turn =1;
	while(!QM.empty())
	{
		if(turn)
		{
			turn=0;
			pm=QM.front();
			QM.pop();
			bool next=true;
			for(int i=0;i<4;i++)
			{
				if(pm.first+arr[i][0]<=0 || pm.first+arr[i][0]>n || pm.second+arr[i][1]<=0 || pm.second+arr[i][1]>m)
				{
					next=false;
					excape=1;
				}
			}
			
			if(next)
			{
				for(int i=0;i<4;i++)
				{
					if(pm.first+arr[i][0]>1 && pm.first+arr[i][1]<n && pm.second+arr[i][1]>1 && pm.second+arr[i][1]<m)
					{
						if(!visit[pm.first+arr[i][0]][pm.second+arr[1][1]])
						{
							p.first=pm.first+arr[i][0];
							p.second=pm.second+arr[i][1];
							QM.push(p);
							visit[0][pm.first+arr[i][0]][pm.second+arr[i][1]]=true;
						}
					}
				}
			}
		} else 
		{
			turn=1;
			pc1=QM1.front(), pc2=QM2.front();
			QM1.pop(); QM2.pop();
			for(int i=0;i<4;i++)
			{
				if(pc1.first+arr[i][0]==pm.first && pc1.second+arr[i][1]==pm.second)
				{
					excape=false;
				} else if(pc2.fist+arr[i][0]==pm.first && pc2.second+arr[i][1]==pm.second)
				{
					escape=false;
				}
			}
			
		
		
		
    system("pause");
}

