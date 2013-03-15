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

node *newnode(int data)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void push(node **headref, int data)
{
	node *temp = newnode(data);
	temp->next = *headref;
	*headref = temp;
}

void remove(node *slow, node *a)
{
	node *ptr1=slow;
	node *ptr2=slow;
	int k=1;
	while(ptr1->next!=ptr2)
	{
		k++;
		ptr1=ptr1->next;
	}
	
	ptr1=a;
	
	ptr2=a;
	for(int i=0;i<k;i++)
		ptr2=ptr2->next;
	
	while(ptr2!=ptr1)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	ptr2=ptr2->next;
	
	while(ptr2->next!=ptr1)
		ptr2=ptr2->next;
	
	ptr2->next=NULL;
}

/* Function to print linked list */
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}

int detectandremove(node *a)
{
	node *fast=a, *slow=a;
	while(slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast!=NULL)
			fast=fast->next;
		if(slow==fast)
		{
			remove(slow, a);
			return 1;
		}
	}
	
	return 0;
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	/* Start with the empty list */
    struct node* head = NULL;
 
    push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 20);
    push(&head, 50);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    detectandremove(head);
 
    printf("Linked List after removing loop \n");
    printList(head);
 
    system("pause");
}

