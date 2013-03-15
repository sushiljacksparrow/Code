#include<iostream>

using namespace std;

struct node
{
	int val;
	node *next;
};

void rotate(node **head_ref, int k)
{
	node *current = *head;
	while(k>0 && current != NULL)
	{
		k--;
		current = current->next;
	}
	
	if(current == NULL)
		return;
	
	node *temp = curren->next;
	
	while(current->next!=NULL)
		current = current->next;
	current->next = *head_ref;
	
	*head_ref = temp;
	temp->next = NULL;
}
	
		
int main()
{
	system("pause");
}
