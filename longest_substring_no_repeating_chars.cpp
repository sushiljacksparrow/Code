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


string longest_substring(string str)
{
	int len = str.size(), currlen =1, maxlen = 1, start = 0;
	int prev;
	int visited[256];
	memset(visited, -1, sizeof(visited));
	visited[str[0]] = 0;
	
	for(int i=1;i<len;i++)
	{
		prev = visited[str[i]];
		if(prev == -1 || i-currlen>prev)
			currlen++;
		else
		{
			if(currlen > maxlen)
			{
				start = i-currlen;
				maxlen = currlen;
			}
			currlen = i-prev;
		}
		visited[str[i]] = i;
	}
	
	if(currlen > maxlen)
		maxlen = currlen;
	free(visited);
//	cout<<maxlen<<endl;
	return str.substr(start, maxlen);
}
	
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	string str="ABDEFGABEF";
//	cin>>str;
	cout<<str<<endl;
	cout<<"Longest substring without repeating characters \t" <<longest_substring(str)<<endl;

    system("pause");
}

