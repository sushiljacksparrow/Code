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

int KthElement(int A[], int m, int B[], int n, int k)
{
	if(n+m<k)
		return -1;
	//cout<<m<<" "<<n<<endl;
	int i = (int)((double)m / (m+n) * (k-1));
  	int j = (k-1) - i;
	
	int Ai_1 = ((i == 0) ? INT_MIN : A[i-1]);
  	int Bj_1 = ((j == 0) ? INT_MIN : B[j-1]);
  	int Ai   = ((i == m) ? INT_MAX : A[i]);
  	int Bj   = ((j == n) ? INT_MAX : B[j]);
 
  	if (Bj_1 < Ai && Ai < Bj)
    	return Ai;
  	else if (Ai_1 < Bj && Bj < Ai)
    	return Bj;
		
	
	if(A[i] < B[j])
		return KthElement(A+i+1, m-i-1, B, j, k-i-1);
	else
		return KthElement(A, i, B+j+1, n-j-1, k-j-1);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int A[] = {1, 2, 3, 4};
	int B[] = {1, 2, 3, 4, 5};
	
	cout<<KthElement(A, 4, B, 5, 9)<<endl;

    system("pause");
}

