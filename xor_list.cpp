#include<iostream>

using namespace std;

struct node
{
	int val;
	node *npx;
};

void insert(node **head_ref, int val)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->val = val;
	temp->npx = ((*head_ref)->npx ^ NULL);
	
	if(*head_ref != NULL)
	{
		node *next = (*head_ref)->npx ^ NULL;
		temp->next = next;
	}
	
	*head_ref = temp;
}

void print_list(node **head_ref)
{
	node *current = *head_ref, prev = NULL;
	node *next;
	while(current != NULL)
	{
		cout<<current->val<<" ";
		next = current->npx ^ prev;
		prev = current;
		current = next;
	}
}
		
int main()
{
	system("pause");
}
