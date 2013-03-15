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

int F[1000];
void failure_function(char *pattern)
{
	int len=strlen(pattern);
	
	F[0]=0, F[1]=0;
	for(int i=2;i<=len;i++)
	{
		int j=F[i-1];
		for(;;)
		{
			if(pattern[j]==pattern[i-1])
			{
				F[i]=j+1;
				break;
			}
			if(j==0)
			{
				F[i]=0;
				break;
			}
			j=F[j];
		}
	}
	
	for(int i=0;i<=len;i++)
		cout<<i<<" "<<F[i]<<endl;
}

void KMP(char *text, char *pattern)
{
	int m=strlen(pattern);
	int n=strlen(text);
	failure_function(pattern);
	int i=0, j=0;
	
	for(;;)
	{
		if(j==n)
			break;
		if(text[j]==pattern[i])
		{
			i++;
			j++;
			if(i==m)
			{
				cout<<"found endin at "<<j-m<<endl;
			}
		}else if(i>0)
		{
				i=F[i];
		} else
		{
				j++;
		}
	}
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	char pattern[1000], text[1000];
	scanf("%s", &text);
	scanf("%s", &pattern);
//	printf("%s", pattern);
//	failure_function(pattern);
	KMP(text, pattern);
    system("pause");
}

