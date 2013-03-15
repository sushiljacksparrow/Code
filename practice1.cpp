// coding practice from leetcode.com 05/03/2013
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

bool pattern_match(char *s, char *p)
{
	assert(s && p);
	if(*p=='\0')
		return *s=='\0';
	if(*(p+1)!='*')
	{
		assert(*p!='\0');
		return ((*p == *s) || (*p=='.' && *s!='\0')) && pattern_match(s+1, p+1);
	}
	
	while((*p==*s) || (*p == '.' && *s!='\0'))
	{
		if(pattern_match(s, p+2))
			return true;
		s++;
	}
	return pattern_match(s, p+2);
}


// top down approach
struct node
{
	node *left, *right;
	int data;
};

int count(node *root, node *a, node *b)
{
	if(root == NULL)
		return 0;
	if(root==a || root==b)
		return 1 + count(root->left, a, b) + count(root->right, a, b);
	else
		return 0;
}

node *LCA(node *root, node *a, node *b)
{
	if(root == NULL)
		return NULL;
	if(root == a || root == b)
		return root;
	int lcount = count(root->left, a, b);
	int rcount = count(root->right, a, b);
	if(lcount == 2)
		return LCA(root->left, a, b);
	else if(rcount == 2)		
		return LCA(root->right, a, b);
	else if(lcount + rcount == 0)
		return NULL;
	else
		return root;
}

// always assume that a->data < b->data
node *LCA_BST(node *root, node *a, node *b)
{
	if(root == NULL)
		return NULL;
	if(root == a || root == b)
		return root;
	else if(root->data < a->data)
		return LCA(root->left, a, b);
	else if(root->data > b->data)
		return LCA(root->right, a, b);
	else if(root->data >= a->data && root->data <= b->data)
		return root;
}

// longest substring without repeating chars

string solve(string str)
{
	int len = str.size();
	int arr[26];
	memset(arr, 0, sizeof(arr));
	
	int start = 0, maxlen = 1, current_len;
	for(int i=1;i<len;i++)
	{
		if(arr[str[i]-'a']==0)
		{
			arr[str[i]-'a']++;
			current_len++;
		} else
		{
			if(current_len > maxlen)
			{
				int k = i-current_len;
				while(str[k]!=str[i])
				{
					arr[str[k]-'a']=0;
					k++;
				}
					
				arr[str[k]-'a']=0;	
				start = i-current_len;
				maxlen = current_len;
				current_len = 1;
			}
		}
	}
	if(current_len > maxlen)
		start = len-current_len;
	return str.substr(start, maxlen); 
}


int find_kth_element(int A[], int m, int B[], int n, int k)
{
	assert(m>=0);
	assert(n>=0);
	assert(k>0);
	assert(m<=m+n);
	
	int i = (int)((double)m/(m+n)*(k-1));
	int j = k-1-i;
	int Ai_1 = (i==0) ? INT_MIN : A[i-1];
	int Bj_1 = (j==0) ? INT_MIN : B[j-1];
	int Ai = (i==m) ? INT_MAX : A[i];
	int Bj = (j==n) ? INT_MAX : B[j];
	
	if(Bj_1 < Ai  && Ai < Bj)
		return Ai;
	else if(Ai_1 < Bj && Bj < Ai)
		return Bj;
		
	assert((Ai > Bj && Ai_1 > Bj) || (Ai < Bj && Ai < Bj_1));
	if(Ai<Bj)
		return find_kth_element(A+i+1, m-i-1, B, n, k-i-1);
	else
		return find_kth_element(A, m, B+j+1, n-j-1, k-j-1);
} 
	
		
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	cout<<solve("abcabcbb");

    system("pause");
}

