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

int arrayJmp ( const vector<int> &A )
{
	int N = A.size();
	int steps[N];
	for(int i=0;i<N;i++)
		steps[i]=99999999;
	steps[0]=0;
	int ind = 0;
	stack<int>S;
	S.push(0);
	while(!S.empty())
	{
		int ind = S.top();
		S.pop();
		if(ind + A[ind]>=N)
			return steps[ind]+1;
		if(steps[ind + A[ind]]==99999999)
		{
			steps[ind+A[ind]]=steps[ind]+1;
			S.push(ind+A[ind]);
		}
	}
	
	return -1;
}
		
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	vector<int>v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(-1);
	v.push_back(1);
	v.push_back(3);
	
	cout<<arrayJmp(v)<<endl;
    system("pause");
}

