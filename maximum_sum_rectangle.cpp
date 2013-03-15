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

#define ROW 4
#define COL 5

int kadane(int arr[], int *start, int *finish, int n)
{
	int current_max = 0, global_max = INT_MIN;
	*start = 0;
	for(int i=0;i<n;i++)
	{
		current_max += arr[i];
		if(current_max<0)
		{
			current_max = 0;
			*start = i+1;
		} else if(current_max > global_max)
		{
			*finish = i;
			global_max = current_max;
		}
	}
	return global_max;
}

int solve(int mat[][COL])
{
	int final_left, final_right, final_top, final_bottom;
	int temp[ROW], start, finish, ans = INT_MIN;
	
	for(int left=0;left<COL;left++)
	{
		memset(temp, 0, sizeof(temp));
		for(int right = left;right<COL;right++)
		{
			for(int i=0;i<ROW;i++)
				temp[i]+=mat[i][right];
			int sum = kadane(temp, 	&start, &finish, ROW);
			if(sum > ans)
			{
				final_left = left;
				final_right = right;
				final_top = start;
				final_bottom = finish;
				ans = sum;
			}
		}
	}
	
	// Print final values
    printf("(Top, Left) (%d, %d)\n", final_top, final_left);
    printf("(Bottom, Right) (%d, %d)\n", final_bottom, final_right);
    printf("Max sum is: %d\n", ans);
}
	
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	 int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };
 
    solve(M);
    system("pause");
}

