

void isCycle(node *head)
{
	node *fast = head, *slow = head;
	
	while(fast!= null && slow!= null && fast->next!= null)
	{
		slow = slow->next;
		fast = fast->next;
		fast = fast->next;
		if(fast == slow)
			remove_loop(fast, head);
	}
	
}

// loop_node is one of the nodes inside the loop
// find the length of the cycle - K
// move one of the node to the Kth node and other to the head
// move these two pointers at the same speed and one will be pointing to another at the beginning of the loop
// point the end of the loop node to NULL
void remove_loop(node *loop_node, node *head)
{
	node *ptr1, *ptr2;
	int k=1;
	ptr1 = loop_node->next;
	while(ptr1!=loop_node)
	{
		k++;
		ptr1 = ptr1->next;
	}
	
	ptr1 = head;
	for(int i=0;i<k;i++)
		ptr1=ptr->next;
		
	ptr2 = head;
	while(ptr1->next!=ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	
	ptr1->next = NULL;
}
	
	
void fun(node **head_ref)
{
	reverse(head_ref);
	int great_so_far = INT_MIN;
	node *current = *head_ref;
	
	node *prev = NULL;
	while(current!=NULL)
	{
		if(current->data > INT_MIN)
		{
			prev->next = current->next;
			free(current);
		}
	}
	
	reverse(head_ref);
}

void reverse(node **head_ref)
{
	node *current = *head_ref;
	node *prev = NULL;
	node *nextptr;
	while(current!=NULL)
	{
		nextptr = current->next;
		current->next = prev;
		current = nextptr;
		prev = current;
	}
	*head_ref = prev;
}

// Reverse alternate K nodes of the linked list
node *reverse_alternate_k(node *head, int k)
{
	node *current = head;
	node *nextptr, prev = NULL;
	for(int i=0;i<k && current != NULL;i++)
	{
		nextptr = current->next;
		current->next = prev;
		prev = current;
		current = nextptr;
	}
	
	if(head != NULL)
		head = current->next;
	
	for(int i=0;k<k && current!=NULL;i++)
		current = current->next;
	
	if(current!=NULL)
		current->next = reverse_alternate_k(current->next, k);
	
	return prev;
}
	
// Reverse a linked list in group of given size

node *reverse_in_groups(node *head, int K)
{
	node *current = head; *prev = NULL, nextptr;
	for(int i=0;i<K && current!=NULL)
	{
		nextptr = current->next;
		current->next = prev;
		prev = current;
		current = nextptr;
	}
	
	if(current->next != NULL)
		head->next = reverse_in_groups(next, K);
		
	return prev;
}
	