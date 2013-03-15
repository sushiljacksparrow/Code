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
void precompute(char pat[], int arr[], int m)
{
	int len=0;
	arr[0]=0;
	int i=1;
	while(i<m)
	{
		if(pat[i]==pat[len])
		{
			len++;
			arr[i]=len;
			i++;
		} else
		{
			if(len!=0)
			{
				len=arr[len-1];
			} else
			{
				arr[i]=0;
				i++;
			}
		}
	}
}

void KMP(char text[], char pat[], int n, int m)
{
	int arr[m];
	precompute(pat, arr, m);
	int i=0, j=0;
	while(i<n)
	{
		if(text[i]==pat[j])
		{
			i++;
			j++;
		}
		if(j==m)
		{
			cout<<i-j<<endl;
			j=arr[j-1];
		}
		else if(text[i]!=pat[j])
		{
			if(j!=0)
				j=arr[j-1];
			else
				i++;
		}
	}
}
						
int main()
{
 	int m;
	cin>>m;
	getchar();
	char ch;
	char pat[m];
	for(int i=0;i<m;i++)
	{
	 	ch=getchar();
		pat[i]=ch;
	} 		
	KMP(pat, pat, m, m);				   	  
 	system("pause");
}
