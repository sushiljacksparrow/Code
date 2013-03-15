/*Sushil Kumar Singh */

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
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	
	
	int n;
	scanf("%d", &n);
	
	vector<int>input(n);
	
	for(int i=0;i<n;i++)
		cin>>input[i];
	
	char mat[n];
	vector< vector<int> > G(n);
	for(int i=0;i<n;i++)
	{
		scanf("%s", mat);
		for(int j=0;j<n;j++)
			if(mat[j]=='Y')
				G[i].push_back(j);
	}
	vector<int> temp;
	queue< vector<int> >Q;
	set< vector<int> > S;
	S.insert(input);
	Q.push(input);
	
	vector<int>ret=input;
	while(!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		bool flag = true;
		for(int i=0;i<n && flag;i++)
			if(ret[i]>temp[i])
				flag = false;
		if(flag==false)
			ret=temp;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<G[i].size();j++)
			{
				swap(temp[i], temp[G[i][j]]);
				if(S.find(temp)==S.end())
				{
					S.insert(temp);
					Q.push(temp);
				}
			}
		}
	}
	printf("%d", ret[0]);
	
	for(int i=1;i<n;i++)
		printf(" %d", ret[i]);
	printf("\n");
		

    system("pause");
}

