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
//http://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int petrol[] = {4,6,7,4};
	int dist[] = {6,5,3,5};
	int n = 4;
	
	int start = 0, end = 1, cap = petrol[start]-dist[start];
	
	while(start != end)
	{
		while(cap < 0 && start != end)
		{
			cap -= (petrol[start] - dist[start]);
			start = (start + 1)%4;
			
			if(start == 0)
				{ printf("No possible \n"); break;}
		}
		
		cap += (petrol[end]-dist[end]);
		end = (end + 1)%n;
		
	}
	cout<<start<<endl;	
			

    system("pause");
}

