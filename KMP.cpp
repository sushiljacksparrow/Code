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

void preprocess(int arr[], int m, char pat[])
{
	arr[0] = 0;
	int len = 0;
	int i = 1;
	while(i<m)
	{
		if(pat[i]==pat[len])
		{
			len++;
			arr[i]=len;
			i++;
		}else
		{
			if(len!=0)
			{
				len = arr[len-1];
			} else
			{
				len = 0;
				i++;
			}
		}
	}
	
//	for(int i=0;i<m;i++)
//		cout<<i<<" "<<arr[i]<<endl;
}

void KMP(char text[], char pat[], int n, int m)
{
//	printf("%s\n", pat);
	int arr[m];
	preprocess(arr, m, pat);
	int i=0, j=0;
	
	while(i<n)
	{
//		cout<<i<<" "<<j<<endl;
		if(text[i] == pat[j])
		{
			i++;
			j++;
		}
		
		if(j==m)
		{
			cout<<"found pattern at \t" << i-j<<endl;
			j = arr[j-1];
		} else if(text[i] != pat[j])
		{
			if(j != 0)
				j = arr[j-1];
			else
				i = i+1;
		}
	}
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	char text[100]="ABABDABACDABABCABAB", pat[20]="ABABCABAB";
	//scanf("%s %s", text, pat);
	KMP(text, pat, strlen(text), strlen(pat));

    system("pause");
}

