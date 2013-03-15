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
#include <utility>

using namespace std;
using namespace __gnu_cxx;

#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define ii pair<int,int>
#define vs vector<string>
#define all(v) (v).begin(), (v).end()
#define For(i,x) for(int i=0;i<x;i++)

struct node
{
 	   string first;
       int second;
};

int sum(string str)
{
 	int len=str.size();
 	int ret=0;
 	for(int i=len-1;i>=0;i--)
 	{
	 		ret = ret*10+(str[i]-'0');
    }
    return ret;
}

int main()
{
 	int n;
 	scanf("%d", &n);
	
	string ans="";
	int digits = n/9+1;
	for(int i=0;i<digits;i++)
			ans+="9";
			
	queue<node> Q;
	node n1;
	n1.first="0";
	n1.second=0;
	Q.push(n1);
	
	while(!Q.empty())
	{
	 	node temp = Q.front();
//	 	cout<<temp.first<<" "<<temp.second<<endl;
	 	Q.pop();
		if(sum(temp.first) == n && temp.second ==0)
		{
		 	cout<<temp.first<<" ";
			break;
		}
		for(int i=0;i<10;i++)
		{
		 		temp.first = temp.first + (i+'0');
		 		int rem = (temp.first*10+i)%n;
		 		n1.first=temp.first*10+i;
		 		n1.second=rem;
		 		Q.push(n1);
		}
	}
	
	system("pause");
}

