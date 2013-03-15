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


node * getNextRight(node *root)
{
	node *temp = root->next;
	while(temp)
	{
		if(temp->left)
			return temp->left;
		else if(temp->right)
			return temp->right;
		else
			temp = temp->next;
	}
	
	return NULL;
}

void connect(node *root)
{
	if(root == NULL)
		return;
	root->next = NULL;
	
	while(root != NULL)
	{
		node *q = p;
		while(q != NULL)
		{
			if(q->left != NULL)
			{
				if(q->right != NULL)
					q->left->next = q->right;
				else
					q->left->next = getNextRight(q);
			}
			
			if(q->right != NULL)
				q->right->next = getNextRight(q);
			q = q->next;
		}
		
		if(p->left != NULL)
			p = p->left;
		else if(p->right != NULL)
			p = p->left;
		else
			p = getNextRight(p);
	}
}	
					
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

