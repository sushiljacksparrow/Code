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

struct trienode
{
	trienode *arr[26];
	int wordcount;
	int minheapindex;
};

struct heapnode
{
	trienode *root;
	int frequency;
	char *word;
};

struct minheap
{
	int capacity;
	int count;
	heapnode *array;
};


trienode *newtrienode()
{
	trienode *root = (trienode *)malloc(sizeof(trienode));
	root->wordcount = 0;
	root->minheapindex = -1;
	for(int i=0;i<26;i++)
		root->arr[i]=NULL;
	return root;
}

minheap * createminheap()
{
	minheap * mh = (minheap*)malloc(sizeof(minheap));
	mh->capacity = 100;
	mh->count = 0;
	mh->array = (heapnode*)malloc(sizeof(heapnode)*100);
	return mh;
}


void insertUtil(minheap **mh, trienode *tr, char *word, char *dupword)
{
	if(tr == NULL)
		tr = newtrienode();
	
	if(*word!='\0')
		insertUtil(mh, tr->word[*word-97], word+1, dupword);
	else
	{
		tr->wordcount++;
		insertinminheap(mh, tr, word);
	}
}
		
void insert(char *word, minheap **mh, trienode *tr)
{
	insertUtil(mh, tc, word, word);
}

void mostfrequentk(char *words[], int n)
{
	minheap *mh = createminheap();
	trienode *tn = NULL;
	
	for(int i=0;i<n;i++)
		insert(words[i], &mh, tn);
		
}
	
	
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

