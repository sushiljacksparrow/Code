#include<iostream>

using namespace std;

struct node
{
	int val;
	node *next;
};

// assume that lists are of same size
node *sum(node *l1, node *l2, int *carry)
{
	if(l1==NULL)
		return 0;
	
	node *temp = (node*)malloc(sizeof(node));
	temp->next = sum(l1->next, l2->next, carry);
	
	int sum = l1->val + l2->val + *carry;
	*carry = sum/10;
	sum = sum%10;
	
	temp->val = sum;
	return temp;
}
	
int main()
{
	system("pause");
}
