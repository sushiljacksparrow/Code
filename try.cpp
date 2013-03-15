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

int dp[40009][7];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int t, a, b, c;
	cin>>t;

	while(t--)
	{
		cin>>a>>b>>c;
		if(c>a && c>b){ cout<<-1<<endl; continue;}
		if(c==a || c==b) { cout<<1<<endl; continue;}
		if(c==0) { cout<<0<<endl; continue;}
		
		memset(dp, 0, sizeof(dp));
		pair<int, int> pi;
		pi.first = a; pi.second = b;
		queue< pair<int, int> > Q;
		Q.push(pi);
		queue<int>QC;
		int count = 0, index1, index2, next;
		QC.push(count);
		bool flag = false;
		while(!Q.empty())
		{
			pi = Q.front(); Q.pop();
			next = QC.front(); QC.pop();
			if(pi.first == 0 && pi.second == 0) { index2 = 0; index1 = pi.first;}
			else if(pi.first == 0 && pi.second != 0) { index2 = 1; index1 = pi.second;}
			else if(pi.first == a && pi.second == 0) { index2 = 2; index1 = pi.first;}
			else if(pi.first == a && pi.second != 0) { index2 = 3; index1 = pi.second;}
			else if(pi.second == 0 && pi.first != 0) { index2 = 4; index1 = pi.first;}
			else if(pi.second == b && pi.first == 0) { index2 = 5; index1 = pi.second;}
			else if(pi.second == b && pi.first != 0) { index2 = 6; index1 = pi.first;}
			
			if(dp[index1][index2] == 1)
				continue;
			dp[index1][index2] = 1;
			
			if(pi.first == c || pi.second == c)
			{
				cout<<next<<endl; 
				flag = true; 
				break;
			}
			
			pair<int, int> temp;
			next++;
			if(pi.second < b)
			{
				temp.first = max(0, pi.first - b + pi.second);
				temp.second = min(b, pi.second + pi.first);
				Q.push(temp); QC.push(next);
				temp.first = pi.first; 
				temp.second = b;
				Q.push(temp); QC.push(next);
			}
			
			if(pi.first < a)
			{
				temp.second = max(0, pi.second - a + pi.first);
				temp.first = min(a, pi.first + pi.second);
				Q.push(temp); QC.push(next);
				temp.first = a;
				temp.second = pi.second;
				Q.push(temp); QC.push(next);
			}
			
			temp.first = 0; temp.second = pi.second; Q.push(temp); QC.push(next);
			temp.first = pi.first; temp.second = 0; Q.push(temp); QC.push(next);
		}
		if(flag == false)
			cout<<-1<<endl;
	}
    system("pause");
}

