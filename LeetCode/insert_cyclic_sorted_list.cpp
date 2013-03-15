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
	node *next, *prev;
};


void insert(node **headr, node *t)
{
	node *head = *headr;
	if(head == NULL)
	{
		head = t;
		return;
	} else if(head->next == head && head->prev == head)
	{
		t->next = head;
		t->prev = head;
		head->next = t;
		head->prev = t;
		if(head->data > t->data)
			*headr = t;
		else
			*headr = head;
	} else
	{
		node *current = head;
		node *prev = current->prev;
		while(current ->next != head && current->data < t->data)
		{
			prev = current;
			current = current->next;
		}
		// reached the end the list
		if(current->next == head)
		{
			t->next = current->next;
			t->prev = current;
			current->next = t;
		} else
		{
			prev->next = t;
			t->next = current;
			current->prev = t;
			t->prev = prev;
		}
	}
}
		
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

