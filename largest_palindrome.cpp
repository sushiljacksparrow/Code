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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	char str[100];
	scanf("%s", &str);
	int len = strlen(str);
	int start = 0, maxlen = 1;
	int low, high;
	for(int i=1;i<len;i++)
	{
		low = i-1, high = i;
		while(low>=0 && high<len && str[low]==str[high])
		{
			if(maxlen < high - low+1)
			{
				maxlen = high - low + 1;
				start = low;
			}	
			low--; high++; 
		}
		
		low = i-1, high = i+1;
		while(low>=0 && high<len && str[low]==str[high])
		{ 
			if(maxlen < high - low+1)
			{
				maxlen = high - low + 1;
				start = low;
			}
			low--; high++; 
		}
		
		//cout<<start<<" "<<maxlen<<endl;
	}
	
	for(int i=start; i<start+maxlen;i++)
		printf("%c", str[i]);
	printf("\n");
    system("pause");
}

