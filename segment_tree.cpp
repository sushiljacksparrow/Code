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

int tree[100];
// forming segment tree to know the sum at the root
int segment_tree(int arr[], int l, int r, int index)
{
	if(l==r)
	{
		tree[index] = arr[l];
		return tree[index];
	}
	int mid = l + (r-l)/2;
	int lval = segment_tree(arr, l, mid, 2*index+1);
	int rval = segment_tree(arr, mid+1, r, 2*index+2);
	tree[index] = lval + rval;
	return tree[index];
}

int query(int ls, int rs, int l, int r, int index)
{
	if(l <= ls && r >= rs)
		return tree[index];
	else if(l>rs || ls > r)
		return 0;
	int mid = ls + (rs-ls)/2;
	return query(ls, mid, l, r, 2*index+1) + query(mid+1, rs, l, r, 2*index+2);
} 

void update_tree_util(int l, int r, int index, int update_index, int diff)
{
	if(update_index < l || update_index > r)
		return;
	tree[index] = tree[index]+diff;
	if(l != r)
	{
		int mid = l + (r-l)/2;
		update_tree_util(l, mid, 2*index+1, update_index, diff);
		update_tree_util(mid+1, r, 2*index+2, update_index, diff);
	}
}

void update_tree(int arr[], int index, int new_val)
{
	int diff = arr[index] - new_val;
	arr[index] = new_val;
	update_tree_util(0, 5, 0, index, diff);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	int arr[] = {1, 3, 5, 7, 9, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	segment_tree(arr, 0, 5, 0);
	
	for(int i=0;i<2*n+2;i++)
		if(tree[i])
			cout<<i<<" "<<tree[i]<<endl;
		
	cout<<"Query "<<0<<" "<<2<<" "<<query(0, 5, 1, 4, 0)<<endl;
	update_tree(arr, 0, 10);
	for(int i=0;i<2*n+2;i++)
		if(tree[i])
			cout<<i<<" "<<tree[i]<<endl;
	cout<<query(0,5, 0, 3, 0)<<endl;
    system("pause");
}

