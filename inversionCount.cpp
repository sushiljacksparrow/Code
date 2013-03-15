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

int merge(int arr[], int temp[], int left, int mid, int right)
{
	int i, j, k, count=0;
	i=left, j=mid, k=left;
	while(i<=mid-1 && j<=right)
	{
		if(arr[i]<arr[j])
			temp[k++]=arr[i++];
		else
		{
			temp[k++]=arr[j++];
			count+=(mid-i);
		}
	}
	
	while(i<=mid-1)
		temp[k++]=arr[i++];
	while(j<=right)
		arr[k++]=arr[j++];
	
	for(i=left; i<=right;i++)
		arr[i]=temp[i];
	return count;
}	


int _mergesort(int arr[], int temp[], int left, int right)
{
	int count=0;
	if(right>left)
	{
		int mid=(left+right)/2;
		count=_mergesort(arr, temp, left, mid);
		count+=_mergesort(arr, temp, mid+1, right);
		
		count+=merge(arr, temp, left, mid+1, right);
	}
	return count;
}

int mergesort(int arr[], int size)
{
	int *temp = (int *) malloc(sizeof(int)*size);
	return _mergesort(arr, temp, 0, size-1);
} 


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	int arr[] = {1, 20, 6, 4, 5};
    printf(" Number of inversions are %d \n", mergesort(arr, 5));
    system("pause");
}

