#include<iostream>

using namespace std;

struct node
{
	int val;
	node *next;
};

node *add(node *l1, node *l2)
{
	node *res = NULL;
	node *temp, *prev = NULL;
	int carry=0, sum;
	
	while(l1!=NULL || l2!=NULL)
	{
		sum = carry + l1!=NULL? l1->val:0 + l2!=NULL? l2->val:0;
		carry = sum>=10 ? 1 : 0;
		sum = sum%10;
		
		temp = (node*)malloc(sizeof(node));
		temp->val = sum;
		
		if(res == NULL)
			res = temp;
		else
			prev->next = temp;
		prev = temp;
		if(l1!=NULL)
			l1=l1->next;
		if(l2!=NULL)
			l2=l2->next;
	}
	
	if(carry)
		temp->next = newnode(carry);
	return res;
}

int main()
{
	system("pause");
}
