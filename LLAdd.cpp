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
	node *next;
	int data;
};

struct node* newnode(int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->next= NULL;
	temp->data = data;
	return temp;
}

void push(node **headref, int data)
{
	node *temp = newnode(data);
	temp->next = *headref;
	*headref = temp;
}

struct node* add(node *a, node *b)
{
	node *res=NULL, *prev = NULL, *temp;
	int carry=0, sum;
	
	
	while(a!=NULL || b!=NULL)
	{
		sum = carry + ((a!=NULL)? a->data : 0) + ((b!=NULL) ? b->data : 0);
		
		carry = (sum>=10) ? 1 : 0;
		sum = sum%10;
		temp = newnode(sum);
		if(res==NULL)
		{
			res=temp;
		} else
		{
			prev->next= temp;
		}
		
		prev=temp;
		if(a)
			a=a->next;
		if(b)
			b=b->next;
	}
	
	if(carry>0)
		temp->next=newnode(carry);
	return res;
}

void printList(node *temp)
{
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
		
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	 struct node* res = NULL;
    struct node* first = NULL;
    struct node* second = NULL;
 
    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);
 
    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is ");
    printList(second);
 
    // Add the two lists and see result
    res = add(first, second);
    printf("Resultant list is ");
    printList(res);
    
    system("pause");
}

