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
	node *left, *right;
};

void BST2DLL(node *p, node * &prev, node *& head)
{
	if(p==NULL)
		return;
	BST2DLL(p->left, prev, head);
	p->left = prev;
	if(prev != null)
		prev->right = p;
	else
		head = p;
		
	node *right = p->right;
	head->left = p;
	p->right = head;
	prev = p;
	BST2DLL(right, prev, head);
}
		
		
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

