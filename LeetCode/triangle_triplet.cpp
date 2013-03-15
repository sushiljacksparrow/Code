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

int triangle (vector<int> &A )
{
	vector<int>B(A);
	sort(B.begin(), B.end());
	for (int i =0; i< B.size() - 2;i++)
	if (B[i] + B[i+1] > B[i+2])
		return 1;
	return 0;
}

//A[0] = 10    A[1] = 2    A[2] = 5
//  A[3] = 1     A[4] = 8    A[5] = 20
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	vector<int>v;
	v.push_back(10);
	v.push_back(2);
	v.push_back(5);
	v.push_back(1);
	v.push_back(8);
	v.push_back(20);
	
	cout<<triangle(v)<<endl;
    system("pause");
}

