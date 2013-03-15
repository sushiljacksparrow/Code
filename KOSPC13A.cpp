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
	int A[10001], B[10001];
	char str1[10001], str2[10001];
	int test;
	cin>>test;
	while(test--) {
//	scanf("%s %s", A, B);
		scanf("%s %s", str1, str2);
		
		int la = strlen(str1), lb = strlen(str2);
		for(int i=0;i<la;i++)
			A[i]=str1[i]-'0';
		for(int i=0;i<lb;i++)
			B[i]=str2[i]-'0';
		int C[la+lb];
		memset(C, 0, sizeof(C));
		int s = la+lb-1;
		
		for(int j=lb-1;j>=0;j--)
		{
			int carry = 0;
			int shift = s;
			for(int i=la-1;i>=0;i--)
			{
				int m = A[i]*B[j];
				int sum = m + C[shift] + carry;
				int num = sum%10;
				int c = sum/10;
				C[shift] = num;
				carry = c;
				shift--;
			}
			C[shift] = C[shift]+carry;
			s--;
		}
		int index = 0;
		while(index<la+lb && C[index]==0)
			index++;
		if(index==la+lb)
			cout<<0<<endl;
		else {
			while(index<la+lb)
				cout<<C[index++];
			cout<<endl;	
		}

		//cout<<endl;
		
	}
	
    system("pause");
}

