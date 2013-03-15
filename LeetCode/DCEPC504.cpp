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


string search(unsigned long long k, unsigned long long n)
{
	vector<unsigned long long>path;
	for(int i=0;i<n;i++)
	{
		path.push_back(k);
		k= (unsigned long long)ceil((float)(k)/2.0);
	}
	//for(int i=0;i<path.size();i++)
	//	cout<<path[i]<<" ";
	//cout<<endl;	
	reverse(path.begin(), path.end());
	string gender = "Male";
	for(int i=1;i<path.size();i++)
	{
		if(path[i]==2*path[i-1])
		{
			if(gender=="Male")
				gender = "Female";
			else if(gender == "Female")
				gender = "Male";
		}
	}
	return gender;		
		
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	unsigned long long t, n, k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<search(k, n)<<endl;
		
	}

    system("pause");
}

