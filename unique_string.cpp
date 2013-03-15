#include<iostream>
#include<string>

using namespace std;

struct node
{
	int word_count;
	node *arr[26];
};

struct node *newnode()
{
	node *t = (node*)malloc(sizeof(node));
	t->word_count;
	for(int i=0;i<26;i++)
		t->arr[i]=NULL;
}

int add_word(node *root, string word)
{
	
	cout<<word<<endl;
	if(word.size()==0)
	{
		if(root->word_count)
			return 0;
		else
		{
			root->word_count=1;
			return 1;
		}
	}
	if(root==NULL)
		cout<<"root was null\n";
	char ch = word[0];
	if(root->arr[ch-'a']==NULL)
	{
		node *temp = newnode();
		root->arr[ch-'a']=temp;
	}
	
	return add_word(root->arr[ch-'a'], word.substr(1));
}

int main()
{
	node *root = newnode();
	string word;
	int count_unique=0;
	while(cin>>word)
	{
		count_unique += add_word(root, word);
	}
	
	cout<<count_unique<<endl;
		
	system("pause");
}
