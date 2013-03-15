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

int dig(int n)
{
	int ret = 0;
	while(n)
	{ n/=10; ret++;}
	return ret;
}

int block[51], bl;	
int m, n;

int getpass(int a, int b)
{
	if(a>b) swap(a, b);
	int cnt = 0;
	for(int i=0;i<bl;i++)
		if(a<block[i] && b>block[i])
			cnt++;
	return cnt;
}

int circ_count(int a, int b)
{
	if(a>b) swap(a, b);
	int ret = abs(n-b) + abs(a-m) + 1;
	int pass = 0;
	for(int i=0;i<bl;i++)
		if((block[i]>b && block[i]<=n) || (block[i]>=m && block[i]<a))
			pass++;
	//cout<<"circ_count "<<a<<" "<<b<<" "<<ret-pass<<endl;
	return ret-pass;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);	
	

	cin>>m>>n;
	

	cin>>bl;
	for(int i=0;i<bl;i++)
		cin>>block[i];
	int ch, channel[101];
	cin>>ch;
	for(int i=0;i<ch;i++)
		cin>>channel[i];
	int ret = dig(channel[0]);
	
	if(ch>1)
	{
		int t = dig(channel[1]);
		
		int pass = getpass(channel[0], channel[1]);
		int cn = abs(channel[1]-channel[0])-pass;
		cn = min(cn, circ_count(channel[0], channel[1]));
		ret += min(t, cn);
		//cout<<ret<<" \n";	
		for(int i=2;i<ch;i++)
		{
			int t = dig(channel[i]);
			pass = getpass(channel[i], channel[i-1]);
			cn = abs(channel[i]-channel[i-1])-pass;
			cn = min(cn, circ_count(channel[i], channel[i-1]));
			t = min(t, cn);
			pass = getpass(channel[i-2], channel[i]);
			cn = 1+abs(channel[i-2]-channel[i])-pass;
			cn = min(cn, circ_count(channel[i-2], channel[i]));
			t = min(t, cn);
			//cout<<channel[i-1]<<" "<<channel[i]<<" "<<t<<endl;
			ret+=t;
		}
		cout<<ret<<endl;
	} else
	{
		cout<<ret<<endl;
	}
    system("pause");
}

