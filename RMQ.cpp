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

int segment_tree(int arr[], int tree[], int l, int r, int index)
{
	if(l == r)
		return tree[index] = arr[l];
	int mid = l+(r-l)/2;
	return tree[index] = min(segment_tree(arr, tree, l, mid, 2*index+1), 
							segment_tree(arr, tree, mid+1, r, 2*index+2));
}

int query(int tree[], int tl, int tr, int l, int r, int index)
{
	cout<<tl<<" "<<tr<<" "<<index<<" "<<l<<" "<<r<<endl;
	system("pause");
	if(l <= tl && r > tr)
		return tree[index];
	if(l > tr || r < tl)
		return INT_MAX;
	int mid = tl+(tr-tl)/2;
	cout<<mid<<endl;
	return min(query(tree, tl, mid, l, r, 2*index+1), query(tree, mid+1, tr, l, r , 2*index+2));
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int arr[] = {2, 5, 1, 4, 9, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	int tree[2*n+2];
	segment_tree(arr, tree, 0, n-1, 0);
	cout<<query(tree, 0, 5, 0, 2, 0)<<endl;
    system("pause");
}

