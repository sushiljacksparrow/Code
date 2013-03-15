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

struct node
{
	char ch;
	int freq;
	node *left, *right;
};

struct minheap
{
	int size;
	int capacity;
	node **heapnode;
};

minheap *create_min_heap(int capacity)
{
	minheap *root = (minheap*)malloc(sizeof(minheap));
	root->size = 0;
	root->capacity = capacity;
	root->heapnode = (node**)malloc(sizeof(node*));
	return root;
}


node *newNode(int freq, char ch)
{
	node *root = (node*)malloc(sizeof(node));
	root->freq = freq; root->ch = ch;
	root->left = root->right;
	return root;
}

void swap_node(node **a, node **b)
{
	node *t = *a;
	*a = *b;
	*b = t;
}

void minheapify(minheap *root, int index)
{
	int smallest = index, left = index*2+1, right = index*2+2;
	
	if(left < root->size && root->heapnode[index]->freq < root->heapnode[left]->freq)
		smallest = left;
	if(right < root->size && root->heapnode[smallest]->freq < root->heapnode[right]->freq)
		smallest = right;
	if(smallest != index)
	{
		swap_node(&root->heapnode[smallest], &root->heapnode[index]);
		minheapify(root, smallest);
	}
}
		
		
void build_min_heap(minheap *root)
{
	int n = root->size-1;
	int i;
	for(i=(n-1)/2;i>=0;i++)
		minheapify(root, i);
}
		
minheap *buildHuffmanTree(char data[], int freq[], int size)
{
	minheap *root = create_min_heap(size);
	for(int i=0;i<size;i++)
		root->heapnode[i] = newNode(freq[i], data[i]);
	root->size = size;
	build_min_heap(root);	
	return root;
}	
	
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

