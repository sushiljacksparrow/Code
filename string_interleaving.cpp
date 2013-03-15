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

void interleaving(string s1_sofar, string s2_sofar, string str)
{
	if(s1_sofar.size() == 0 && s2_sofar.size() == 0)
	{
		cout<<str<<endl;
		return;
	}
	if(s1_sofar.size()==0)
	{
		cout<<str + s2_sofar<<endl;
	} else if(s2_sofar.size() == 0)
	{
		cout<<str + s1_sofar<<endl;
	} else
	{
		interleaving(s1_sofar.substr(1), s2_sofar, str+s1_sofar[0]);
		interleaving(s1_sofar, s2_sofar.substr(1), str+s2_sofar[0]);
	}
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	string s1 = "AB";
	string s2 = "CD";
	
	interleaving(s1, s2, "");

    system("pause");
}

