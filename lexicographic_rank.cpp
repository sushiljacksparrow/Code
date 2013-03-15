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

int fact(int n)
{
	return (n<=1) ? 1 : n*fact(n-1);
}

int find_smaller(char str[], int low, int len)
{
	int ret = 0;
	for(int i=low+1;i<=len;i++)
		if(str[low]>str[i])
			ret++;
	return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	char str[100];
	scanf("%s", str);
	int len = strlen(str);
	int mul = fact(len);
	int rank = 1;
	int count_right;
	
	for(int i=0;i<len;i++)
	{
		mul = mul/(len-i);
		count_right = find_smaller(str, i, len-1);
//		cout<<i<<" "<<count_right<<" "<<mul<<endl;
		rank += count_right * mul;
	}
	
	cout<<rank<<endl;	
    system("pause");
}

