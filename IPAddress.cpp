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


void generateIPUtil( char* str, char* output, int depth, int countDot, int val )
{
        if( !*str )
        {
                output[depth] = '\0';
                if( countDot == 3 && output[depth-1] != '.' )
                        printf( "%s\n", output );
        }
        else
        {
                output[depth] = *str;
                val = val * 10 + *str - '0';
                if( val <= 255 )
                {
                	if( countDot < 3)
                	{
                        output[depth + 1] = '.';
                        generateIPUtil( str+1, output, depth+2, countDot+1, 0 );
                	}
                	generateIPUtil( str+1, output, depth+1, countDot, val );
                }
        }
}
	
		
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	char outout[30];
	generateIPUtil("12344", outout, 0, 0, 0);
    system("pause");
}

