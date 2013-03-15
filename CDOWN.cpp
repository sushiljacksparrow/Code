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

map<string, string> mp;
int len;

int sove(vector< pair<string, string> > vp, string s, int d)
{
	if(mp[s]!=0)
		return mp[s];
	int count=0;
		
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	vector< pair<string, string> > vp;
	int n, d, t;
	string s1, s2;
	cin>>n>>d;
	pair<string, string> p;
	mp.clear();
	set<string>ss;
	for(int i=0;i<n;i++)
	{
		cin>>s1>>t;
		p.first=s1;
		ss.insert(s1);
		while(t--)
		{
			cin>>s2;
			p.second=s2;
			vp.push_back(p);
			ss.insert(s2);
		}
		
	}

	len=vp.size();
	set<string>::iterator it;
	for(it=ss.begin(); it!=ss.end();it++)
	{
		string s = *it;
		if(mp[s]!=0)
		{
			solve(vp, s, d);
		}
	}
		
    system("pause");
}

