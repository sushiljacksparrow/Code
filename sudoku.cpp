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


#define N 9

bool solve(int grid[N][N])
{
	bool flag=true;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(grid[i][j]==-1)
				{flag=false; break;}
				
	if(flag==true)
		return true;
		
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(grid[i][j]==-1)
			{
				for(int k=1;k<=9;k++)
				{
					grid[i][j]=k;
					if(solve(grid))
						return true;
					
					grid[i][j]=-1;
				}
			}
		}
	}
	
	return false;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

