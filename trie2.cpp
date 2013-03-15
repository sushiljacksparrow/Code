#include<iostream>
#include<cstring>
 
using namespace std;
 
struct node{
	int prefix;
	int word;
	char ch;
	node *child[26];	
};
 
void initialise(struct node *&vertex){
	vertex->prefix=0;
	vertex->word=0;
	vertex->ch='\0';
	for(int i=0;i<26;i++)
		vertex->child[i]=NULL;	
}
 
int insert_trie(struct node *&vertex,string s){
	if(s.empty()){
		vertex->word=vertex->word+1;
		return 1;
	}
	else{
		char c=s[0];
		int key=((int)c)-65;
		vertex->prefix=vertex->prefix+1;
		if(vertex->child[key]==NULL){
			node *nwnode=new node;
			initialise(nwnode);
			nwnode->ch=c;
			vertex->child[key]=nwnode;
		}
		s.erase(s.begin());
		insert_trie(vertex->child[key],s);
	}
}
 
int count_word(struct node *vertex,string s){
	if(s.empty()){
		return vertex->word;
	}
	else {
			char c=s[0];
		int key=((int)c)-65;	
	if(vertex->child[key]==NULL)
		return 0;
	else{
		s.erase(s.begin());
		count_word(vertex->child[key],s);
	}
	}
}
 
int count_prefix(struct node *vertex,string prefix){
	if(prefix.empty())
		return vertex->prefix;
	else{
		char p=prefix[0];
		int key=((int)p)-65;
	 if(vertex->child[key]==NULL)
		return 0;
	else{
		prefix.erase(prefix.begin());
		count_prefix(vertex->child[key],prefix);
	}
	}
}
 
int main()
{
	struct node *root=new node;
	initialise(root);
	int n;
	cout<<"enter no of strings\n";
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
		insert_trie(root,s[i]);
	}
 
	for(int i=0;i<n;i++){
		cout<<count_word(root,s[i])<<"\n";	
	}
	string str;
	cout<<"enter prefix string\n";
	cin>>str;
	cout<<count_prefix(root,str)<<"\n";
	
	return 0;
}
