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
	
	string str;
	while(cin>>str && str!="*") {
	int n = str.size();
	int arr[n];
	arr[0] = 0;
	int len = 0;
	int i = 1;
	while(i<n)
	{
		if(str[i]==str[len])
		{
			len++;
			arr[i]=len;
			i++;
		} else
		{
			if(len!=0)
			{
				len = arr[len-1];
			} else
			{
				arr[i] = 0;
				i++;
			}
		}
	}
	//for(int i=0;i<n;i++)
	//	cout<<arr[i]<<" ";
	//cout<<endl;
	int k = 0;
	bool success = false;
	for(;k<n && !success;k++)
	{
		if(arr[k] != 0)
		{
			bool flag = true;
			int t = k;
			//cout<<"dasda\n";
			for(int i=2*k-1;i<n;i+=k)
			{
			//	cout<<k<<" "<<i<<" "<<arr[i]<<" "<<t<<endl;
				if(arr[i] != t)
					flag = false;
				t+=k;
			//	system("pause");
			}
			//cout<<flag<<" "<<k<<endl;
			if(flag == true) 
			{
				int ans = n/k;
				//cout<<n<<" "<<ans<<" "<<k<<endl;
				if(ans*k == n)
				{
					cout<<ans<<endl;
					success = true;
				}
			}
		}
	}
	if(success == false)
		cout<<1<<endl;	
  }
	//}


	
	system("pause");
}

