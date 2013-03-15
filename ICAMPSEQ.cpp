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
inline double Read_Double ( void )
{
    bool Negative = false;
    char Ch;
 
    while ( ! isdigit ( Ch = Read_Char ( ) ) ) if ( Ch == '-' ) Negative = true;
        else Negative = false;
 
    double Ret = Ch - '0';
 
    while ( isdigit ( Ch = Read_Char ( ) ) ) Ret = Ret * 10 + ( Ch - '0' );
 
    double Mul = 1.00;
 
    if ( Ch == '.' )
    {
        while ( isdigit ( Ch = Read_Char ( ) ) )
        {
            Mul /= 10.00;
 
            Ret += ( Ch - '0' ) * Mul;
        }
    }
 
    if ( Negative ) Ret *= -1.00;
 
    return Ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int test;
	cin>>test;
	
    //return Ret;
    system("pause");
}

