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

#define vs vector<string>
#define all(v) (v).begin(), (v).end()
#define For(i,x) for(int i=0;i<x;i++)


int zigzag(vector<int>seq)
{
	if(seq.size()==1)
		return 1;
	int len=seq.size();
	vector<int>dp(len-1);
	for(int i=1;i<len;i++)
		dp[i-1]=seq[i]-seq[i-1];
	
	int ii=0;
	while(ii<seq.size() && dp[ii]==0)
		ii++;
	if(ii==seq.size())
		return 1;
	
	int dir=dp[ii];
	int ret=2;
	for(int i=ii+1;i<dp.size();i++)
	{
		if(dp[i]*dir<0)
		{
			dir*=(-1);
			ret++;
		}
	}
	return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	vector<int>vi;
	int n,num;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num, vi.push_back(num);
	cout<<zigzag(vi)<<endl;

    system("pause");
}

