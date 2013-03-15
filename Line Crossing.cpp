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
	int n;
	cin>>n;
	int arr[100009][4]; // x1, y1, x2, y2;
	int x, y, l;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d", x,y,l);
		arr[i][0]=x;
		arr[i][1]=y;
		arr[i][2]=x+l;
		arr[i][3]=y;
	}
	int Q;
	cin>>Q;
	for(int i=0;i<Q;i++)
	{
		scanf("%d %d %d", &x, &y, &l);
		int x1=x, y1=y, x2=x, y2=y+l;

    system("pause");
}

