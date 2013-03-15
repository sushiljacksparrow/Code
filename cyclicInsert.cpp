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
	node *next;
};

// assume that temp is not null and already has the values
void (node &*head, node *temp)
{
	// check the case of empty linked list
	if(*head==null)
	{
		*head = (node*)malloc(sizeof(node*));
		head->next = head;
		head->data = temp->data;
		return;
	}
	
	// check the case when linked list has just one value
	if(*head->next==*head)
	{
		temp->next=*head;
		*head->next=temp;
		if(temp->data < *head->date)
			*head=temp;
		return;
	}
	
	node *current = *head;
	while(current != null)
	{
		current=current->next;
		if(current->next==head) // reached the first element
		{
			temp->next=head;
			current->next=temp;
			return;
		}
	}
	
	temp->next = current->next->next;
	current->next=temp;
}
		
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);


    system("pause");
}

