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

	int n1, n2, s1, s2, ret;
	int seq1[10001], seq2[10001];
	
	while(true)
	{
		scanf("%d", &n1);
		if(n1==0)
			break;
		for(int i=0;i<n1;i++)
			scanf("%d", &seq1[i]);
		scanf("%d", &n2);
		for(int j=0;j<n2;j++)
			scanf("%d", &seq2[j]);
			
		s1=0, s2=0, ret=0;
		int c1=0, c2=0;
		while(c1<n1 || c2<n2)
		{
			if(c1<n1 && c2<n2 && seq1[c1]>seq2[c2])
			{
				s2+=seq2[c2];
				c2++;
			} else if(c1<n1 && c2<n2 && seq1[c1]<seq2[c2])
			{
				s1+=seq1[c1];
				c1++;
			} else if(c1<n1 && c2<n2 && seq1[c1]==seq2[c2])
			{
				ret+=max(s1,s2)+seq1[c1];
				s1=0;
				s2=0;
				c1++;
				c2++;
			} else 
			{
				if(c1==n1)
				{
					while(c2<n2)
						s2+=seq2[c2++];
				} else if(c2==n2)
				{
					while(c1<n1)
						s1+=seq1[c1++];
				}
				if(s1>s2)
					ret+=s1;
				else if(s2>s1)
					ret+=s2;
			}
		}
		printf("%d\n", ret);
	} 
					
    system("pause");
}

