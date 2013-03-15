#include<iostream>


struct index_node
{
	int index;
	index_node *next;
};

struct trie_node
{
	int words;
	trie_node arr[26];
	index_node *head;
};

node *new_trie_node()
{
	trie_node *temp = (trie_node*)malloc(sizeof(trie_node));
	for(int i=0;i<26;i++)
		temp->arr[i]=NULL;
	temp->words=0;
	temp->head = NULL;
	return temp;
}

node *new_index_node(int ind)
{
	index_node *temp = (index_node*)malloc(sizeof(index_node));
	temp->index = ind;
	temp->next = NULL;
	return temp;
}


void insert(char *sorted_word, int index, trie_node *root)
{
	if(*sorted_word=='\0')
	{
		if(root->word>0)
		{
			index_node *temp = root->head;
			while(temp->next!=NULL)
				temp = temp->next;
			temp->next = new_index_node(index);
		} else
		{
			root->head = new_index_node(index);
		}
	} else
	{
		if(root->arr[*sorted_word-'a']==NULL)
		{
			root->arr[*sorted_word-'a'] = new_trie_node();
			insert(sorted_word+1, index, root->arr[*sorted_word-'a']);
		} else
		{
			insert(sorted_word+1, index, root->arr[*sorted_word-'a']);
		}
	}
}

			