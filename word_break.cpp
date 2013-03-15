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


map<string, string> mapp;
string word_break(string input, set<string>dict)
{
	if(dict.find(input) != dict.end())
		return input;
	if(mapp[input]!="")
		return mapp[input];
	int len = input.size();
	for(int i=0;i<=len;i++)
	{
		string prefix = input.substr(0,i);
		if(dict.find(prefix) != dict.end())
		{
			string suffix = input.substr(i);
			string ret = word_break(suffix, dict);
			if(ret.size()>0)
			{
				mapp[input] = prefix + " " + ret;
				return mapp[input];
			}
		}
	}
	return "";
}
			
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	set<string>s;
	s.insert("google"); s.insert("engine"); s.insert("search"); s.insert("is"); s.insert("a");
	cout<<word_break("googlesearchengineisagooglesearch", s)<<endl;

    system("pause");
}

