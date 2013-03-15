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

template <typename UnsignedT>
UnsignedT bit_rev(UnsignedT u)
{
    UnsignedT ret = UnsignedT();

    std::size_t n;
    for (n = CHAR_BIT * (sizeof (UnsignedT)); n > 0 && !(u & (static_cast<UnsignedT>(0x1) << (n - 1))); --n);

    std::size_t i;
    for (i = 0; i < n; ++i) {
        ret |= ((u >> i) & 0x1) << (n - i - 1);
    }
    return ret;
}

long least_symmetric_binary_root(unsigned long N)
{
	long ret = -1;
	unsigned long floor_sqrt_N = static_cast<unsigned long>(std::sqrt(static_cast<long double>(N)));
    while ((floor_sqrt_N + 1) * (floor_sqrt_N + 1) < N) {
        ++floor_sqrt_N;
    }

    unsigned long a;
    for (a = 1; a <= floor_sqrt_N; ++a) {
        if (N % a == 0) {
            unsigned long q = N / a;
            if (bit_rev(a) == q) { 
            } else if (bit_rev(q) == a)
			{
                ret = (ret == -1 ? q : std::min(ret, static_cast<long>(q)));
            }
        }
    }

    return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	cout<<least_symmetric_binary_root(55UL)<<endl;

    system("pause");
}

