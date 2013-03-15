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

bool match(char *s, char *p)
{
	if(*p=='\0')
		return *s=='\0';
	if(*(p+1)!='*')
	{
		return ((*p==*s) || (*p=='.' && *s!='\0')) && match(s+1, p+1);
	}
	
	while((*p==*s) || (*p=='.' && *s!='\0'))
	{
		if(match(p, s+2))
			return true;
		s++;
	}
	return match(s, p+2);
}		
		
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	char s[10], p[10];
	scanf("%s", s);
	scanf("%s",  p);
	cout<<match(s, p)<<endl;

    system("pause");
}

