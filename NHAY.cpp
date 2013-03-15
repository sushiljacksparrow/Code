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


// Get all the prefix of pat and find the longest proper suffix of each of them
int arr[1000009];
string pat, text;
int m;
void failure_func()
{
	arr[0]= arr[1]=0;
	for(int i=2;i<=m;i++)
	{
		int j=arr[i-1];
		while(1)
		{
			if(pat[j]==pat[i-1])
			{
				arr[i]=j+1;
				break;
			}
			if(j==0)
			{
				arr[i]=0;
				break;
			}
			j=arr[j];
		}
	}
	
	//for(int i=0;i<=m;i++)
	//	cout<<i<<" "<<arr[i]<<endl;
}

	
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	
	bool first = true;
	
	while(cin>>m>>pat>>text)
	{
		vector<int>output;
		failure_func();
		
		int n=text.size();
		int i=0, j=0;
		while(1)
		{
			if(j==n)
				break;
			if(text[j]==pat[i])
			{
				i++;
				j++;
				if(i==m)
				{
					output.push_back(j-i);
				//cout<<j-i<<endl;
					i=arr[i];
				}
			} else if(i>0)
				i=arr[i];
			else
				j++;
		}
		if(first)
			first=false;
		else
			cout<<endl;
		for(int i=0;i<output.size();i++)
			cout<<output[i]<<endl;
	}
    system("pause");
}

