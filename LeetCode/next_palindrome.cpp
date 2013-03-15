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

void generate_next_palindrome(int arr[], int n)
{
	int mid=n/2;
	int i = mid-1;
	int j = (n%2==1)? mid+1 : mid;
	
	bool flag = false;
	while(i>=0 && arr[i]==arr[j])
		i--, j++;
	if(i<0 || arr[i]<arr[j])
		flag = true;
	
	while(i>=0)
	{
		arr[j]=arr[i];
		i--;
		j++;
	}
	
	if(flag)
	{
		int carry = 1;
		i=mid-1;
		if(n%2==1)
		{
			int t = arr[mid]+1;
			if(t>=10)
				carry=1, arr[mid]=t%10;
			else
				carry=0, arr[mid]=t;
			j=mid+1;
		} else
		{
			j=mid;
		}
		
		while(i>=0)
		{
			arr[i]+=carry;
			carry=arr[i]/10;
			arr[i]%=10;
			arr[j++]=arr[i--];
		}
	}
}
			
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int arr[]={9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	generate_next_palindrome(arr, n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
    system("pause");
}

