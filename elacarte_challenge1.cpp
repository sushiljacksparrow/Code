/*Sushil Kumar Singh */
//http://www.elacarte.com/challenge/1/
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

#define all(v) (v).begin(), (v).end()
#define For(i,x) for(int i=0;i<x;i++)

int mat[10771][200];
int main()
{
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

	
	vector<string> vs;
	string str;
	while(cin>>str)
	{
		vs.push_back(str);
	}
//	cout<<vs.size()<<endl;	
	int n = vs.size(), m = vs[0].size();	
	
	memset(mat, 0, sizeof(mat));
	
	for(int i=0;i<n;i++)
		mat[i][0]=(vs[i][0]=='P');
	for(int i=1;i<m;i++)
		mat[0][i]=(vs[0][i]=='P');

	
	int ret=0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(vs[i][j]=='P')
			{
				mat[i][j]=max(mat[i-1][j], mat[i][j-1]);
				ret=max(ret, mat[i][j]);
			} else
			{
				mat[i][j]=0;
			}
		}
	}
	
	cout<<ret<<endl;
    system("pause");
}

