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


string smallest_window(string s, string t)
{
	cout<<s<<" "<<t<<endl;
	int m = s.size(), n = t.size();
	int need_to_find[26], has_found[26];
	memset(need_to_find, 0, sizeof(need_to_find));
	memset(has_found, 0, sizeof(has_found));
	for(int i=0;i<n;i++)
		need_to_find[t[i]-'A']++;
	int max_begin = 0, max_len = INT_MAX, begin = 0, count = 0;
	for(int i=0;i<m;i++)
	{
		//cout<<s[i]<<endl;
		if(need_to_find[s[i]-'A']==0)
			continue;
		has_found[s[i]-'A']++;
		if(has_found[s[i]-'A'] <= need_to_find[s[i]-'A'])
			count++;
		//cout<<i<<" "<<count<<endl;
		if(count == n)
		{
			while(has_found[s[begin]-'A']==0 || has_found[s[begin]-'A'] > need_to_find[s[begin]-'A'])
			{
				if(has_found[s[begin]-'A']>need_to_find[s[begin]-'A'])
					has_found[s[begin]-'A']--;
				begin++;
			}
			if(i-begin+1 < max_len)
			{
				//cout<<i<<" "<<max_begin<<endl;
				max_begin = begin;
				max_len = i-begin+1;
			}
		}
	}
	cout<<max_begin<<" "<<max_len<<endl;
	if(max_len == INT_MAX)
		return "";
	else
		return s.substr(max_begin, max_len);
}
					

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	cout<<smallest_window("ADOBECODEBANC", "ABC")<<endl;

    system("pause");
}

