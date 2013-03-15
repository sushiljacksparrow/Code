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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int arr[10009];
	memset(arr, 0, sizeof(arr));
	int n1, n2, n3;
	//int arr[10009][3];
	while(cin>>n1>>n2>>n3)
	{
		for(int i=n1;i<=n3;i++)
			arr[i]=max(arr[i], n2);
	}
	for(int i=0;i<50;i++)
		cout<<i<<" "<<arr[i]<<endl;
	cout<<endl;
	for(int i=0;i<10009;i++)
	{
		if(arr[i]>arr[i+1])
			cout<<i<<" "<<arr[i]<<endl;
		else if(arr[i]<arr[i+1])
			cout<<i+1<<" "<<arr[i]<<endl;
	}	
    system("pause");
}

