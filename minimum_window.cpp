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


void minimum_window(char *s, char *t, int &min_begin, int &min_end)
{
	int slen=strlen(s);
	int tlen=strlen(t);
	
	int hasfound[256]={0};
	int need[256]={0};
	
	for(int i=0;i<tlen;i++)
		need[t[i]]++;
	
	int count=0;
	int min_len=INT_MAX;
	for(int begin=0, end=0;end<slen;end++)
	{
		char ch=s[end];
		if(need[ch]==0)
			continue;
		hasfound[ch]++;
		count++;
		
		if(count==tlen)
		{
			while(need[s[begin]]==0 || hasfound[s[begin]] > need[s[begin]])
			{
				if(need[s[begin]]>hasfound[s[begin]])
					hasfound[s[begin]]--;
				begin++;
			}
		}
		
		int currentlen=end-begin+1;
		if(currentlen>min_len)
		{
			min_begin=begin;
			min_end=end;
			min_len=currentlen;
		}
	}
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

