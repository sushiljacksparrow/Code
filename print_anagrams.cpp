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

struct trie_node
{
	bool isEnd;
	trie_node *arr[26];
	vector<int>index;
};

trie_node *newNode()
{
	trie_node *root = (trie_node*)malloc(sizeof(trie_node));
	root->isEnd = false;
	for(int i=0;i<26;i++)
		root->arr[i] = false;
	return root;
}

void insert(trie_node *root, char *str, int ind)
{
	if(root == NULL)
		root = newNode();
	if(*str == '\0')
	{	
		root->isEnd = true; 
		root->index.push_back(ind);
		return;
	}		
	
	char ch = str[0];
	if(root->arr[ch-'a'])
	{
		insert(root->arr[ch-'a'], str+1, ind);
	} else
	{
		trie_node *temp = newNode();
		root->arr[ch-'a'] = temp;
		insert(temp, str+1, ind);
	}
}

void traverse(trie_node *root)
{
	if(root == NULL)
		return;
	
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	char *strings[] = {"cat", "act", "dog", "god", "ram"};
	
	

    system("pause");
}

