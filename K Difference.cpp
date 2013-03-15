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

unsigned long long arr[100009];
int N;
unsigned long long K;
map<unsigned long long, int>mapp;
int search(unsigned long long val)
{
	int end=N, start=1;
	int mid;
	
	while(end>=start)
	{
		mid=(start+end)/2;
		if(arr[mid]==val)
		{
			return mapp[val];
		} else if(arr[mid] > val)
		{
			end=mid-1;
		} else
		{
			start=mid+1;
		}
		//cout<<start<<" "<<end<<endl;
		//system("pause");
	}
	return 0;
}
		
			
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	

	cin>>N>>K;

	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
		mapp[arr[i]]++;
	}
	sort(arr, arr+N);
	int count=0;
	for(int i=0;i<N;i++)
	{
		//cout<<count<<endl;
		//cout<<search(i+1, arr[i]+K)<<endl;
		count+=search(arr[i]+K);
	}
	cout<<count<<endl;	
    system("pause");
}

