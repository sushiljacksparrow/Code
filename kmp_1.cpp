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
void preprocess(int arr[], int m, string str)
{
	memset(arr, 0, sizeof(arr));
	arr[0] = 0;
	int len = 0, i=1;
	while(i<m)
	{
		if(str[i]==str[len])
		{
			len++;
			arr[i] = len;
			i++;
		} else
		{
			if(len!=0)
				len = arr[len-1];
			else
			{
				arr[i] = 0;
				i++;
			}
		}
	}
	for(int i=0;i<m;i++)
		cout<<i<<" "<<arr[i]<<endl;
}
			
void KMP(string s, string t)
{
	int n = s.size(), m = t.size();
	int arr[m];
	preprocess(arr, m, t);
	int i = 0, j = 0;
	while(i<n)
	{
		if(s[i]==t[j])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			cout<<"found string at "<<i-j<<endl;
			j=arr[j-1];
		} else if(s[i] != t[j])
		{
			if(j!=0)
				j = arr[j-1];
			else
			{
				i++;
			}
		}
	}
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	string s = "ABCADABCA", t = "ABCA";
	KMP(s, t);

    system("pause");
}

