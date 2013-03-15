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


int print_petrol(int P[], int D[], int n)
{
	int tank = P[0]-D[0];
	int start = 0, end = 1;
	while(start != end || tank < 0)
	{
		while(tank < 0 && start != end)
		{
			tank -= (P[start]-D[start]);
			start = (start+1)%n;
			if(start == 0)
				return -1;
		}
		tank += P[end] - D[end];
		end = (end+1)%n;
	}
	return start;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int P[] = {6, 3, 7};
	int D[] = {4, 6, 3};

 
    int n = sizeof(P)/sizeof(P[0]);
    int start = print_petrol(P, D, n);
 
    (start == -1)? printf("No solution"): printf("Start = %d", start);
    cout<<endl;
    system("pause");
}

