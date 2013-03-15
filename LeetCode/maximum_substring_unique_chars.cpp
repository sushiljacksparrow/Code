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


string unique_chars(string str)
{
	bool chars[256] = {false};
	int j=0, i=0;
	int len = str.size();
	int st = 0, end = 0;
	int max_len = 0;
	while(j<len)
	{
		if(chars[str[j]-'a'])
		{
			if(max_len < j-i)
			{
				max_len = j-i;
				st = i;
				end = j;
			}
			while(str[j]!=str[i])
			{
				chars[str[i]-'a']=false;
				i++;
			}
			i++;
			j++;
		} else
		{
			chars[str[j]-'a']=true;
			j++;
		}
	}
	
	return str.substr(st, end-st);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	string str="b";

		cout<<unique_chars(str)<<endl;
		

    system("pause");
}

