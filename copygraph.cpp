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
	int data;
	vector<node*>neighbour;
};

node *copygraph(node *root)
{
	map<node*, node*>mapp;
	queue<node*>Q;
	Q.push(root);
	node *root1 = (node*)malloc(sizeof(node*));
	mapp[root]=root1;
	
	while(!Q.empty())
	{
		node *temp = Q.front();
		Q.pop();
		int n = temp->neighbour.size();
		for(int i=0;i<n;i++)
		{
			node *next = temp->neighbour[i];
			if(mapp.find(next)==mapp.end())
			{
				node *temp1 = (node*)malloc(sizeof(node*));
				mapp[temp]->neighbour.push_back(temp1);
				mapp[next]=temp1;
				Q.push(next);
			} else
			{
				mapp[temp]->neighbour.push_back(mapp[next]);
			}
		}
	}
	
	return root1;
}
			
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

