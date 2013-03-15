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
    int A, B, C;
    
    int arr[40009][8];
    memset(arr, -1, sizeof(arr));
	cin>>A>>B>>C;
	
	queue< pair<int, int> > Q;
	queue<int>QC;
	
	Q.push(make_pair(A, B));
	QC.push(2);
	pair<int, int> current;
	int curr_val;
	while(!Q.empty())
	{
		current = Q.front();
		Q.pop();
		curr_val = QC.front();
		QC.pop();
		int ind1, inde2;
		if(current.first == 0 && current.second == 0)
		{	ind1 = 0; ind2 = 0; }
		else if(current.first != 0 && current.second == 0)
		{ ind1 = current.first; ind2 = 1;}	
		else if(current.first == 0 && current.second == B)
		{ ind1 = 0; ind2 = B;}
		else if(current.first == 0 && current.second != 0)
		{ ind1 = 0; ind2 = current.second;}
		else if(current.first == A && current.second == 0)
		{ ind1 = A; ind2 = 0;}
		
		
    system("pause");
}

