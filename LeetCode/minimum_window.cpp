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


string minimum_window(string s, string t)
{
	int slen = s.length();
	int tlen = t.length();
	
	int need[26];
	memset(need, 0, sizeof(need));
	for(int i=0;i<tlen;i++)
		need[t[i]-'a']++;
		
	int seen[26];
	memset(seen, 0, sizeof(seen));
	
	int count =0;
	int maxlen =INT_MAX;
	int beginwindow =0;
	int endwindow = 0;
	
	for(int begin =0, end =0;end <slen;end++)
	{
		cout<<count<<endl;
		if(need[s[end]-'a']==0)
			continue;
		seen[s[end]-'a']++;
		if(need[s[end]-'a'] >= seen[s[end]-'a'])
			count++;
		if(count == tlen)
		{
			while(need[s[begin]-'a'] == 0 || (need[s[begin]-'a'] < seen[s[begin]-'a']))
			{
				if(need[s[begin]-'a'] < seen[s[begin]-'a'])
					seen[s[begin]-'a']--;
				begin++;
			}
			if(maxlen > end-begin+1)
			{
				beginwindow = begin;
				endwindow = end;
				maxlen = end-begin+1;
			}
		}
	}
	
	cout<<beginwindow<<" "<<endwindow<<endl;
	return s.substr(beginwindow, maxlen);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	string s = "ADOBECODEBANC";
	string t = "ABC";
	cout<<minimum_window(s, t)<<endl;
    system("pause");
}

