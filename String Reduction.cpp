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
	int test;
	cin>>test;
	string input;
	int arr[3]={0};
	while(test--)
	{
		memset(arr, 0, sizeof(arr));
		cin>>input;
		int a=0,b=0,c=0;
		for(int i=0;i<input.size();i++)
		{
			if(input[i]=='a')
				a++;
			else if(input[i]=='b')
				b++;
			else
				c++;
		}
		
		if((a==0 && b==0) || (b==0 && c==0) || (a==0 && c==0))
			cout<<input.size()<<endl;
		else if((a%2==0 && b%2==0 && c%2==0) || (a%2==1 && b%2==1 && c%2==1))
			cout<<2<<endl;
		else
			cout<<1<<endl;
	}
	system("pause");
//	system("pause");
}

