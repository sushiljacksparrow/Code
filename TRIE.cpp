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
	int prefix;
	int word;
	node *arr[26];
};

node * initialize(node * &n)
{
	n->prefix = 0;
	n->word = 0;
	for(int i=0;i<26;i++)
		n->arr[i]=NULL;
}

void addword(node * &n, string str)
{
	if(str.size()==0)
	{
		n->word = n->word+1;
		return;
	} else 
	{
		n->prefix = n->prefix+1;
		char ch=str[0];
		if(n->arr[ch-'a']==NULL)
		{
			node* temp = (node*)malloc(sizeof(node*));
			initialize(temp);
			n->arr[ch-'c']=temp;
		}
		addword(n->arr[ch-'a'], str.substr(1));
	}
}

int countWords(node *n, string str)
{
 	cout<<str<<endl;
	if(str.size()==0)
		return n->word;
	else
	{
 	 	if(n==NULL)
            return 0;
	   else
	   	   	return countWords(n->arr[str[0]-'a'], str.substr(1));
	}
}

int countPrefix(node *n, string str)
{
	if(str.size()==0)
		return n->prefix;
	else
	{
	 	if(n == NULL)
			 return 0;
		 else 
		 {
		  	  return countPrefix(n->arr[str[0]-'a'], str.substr(1));
	     }
    }
}

			
	
int main()
{
	int n;
	node * root= (node*)malloc(sizeof(node*));
	initialize(root);
	cout<<"enter no of strings\n";
	cin>>n;
	string s[10];
	for(int i=0;i<n;i++){
		cin>>s[i];
		addword(root,s[i]);
	}
 	cout<<"ddads";
	for(int i=0;i<n;i++){
		cout<<countWords(root,s[i])<<"\n";	
	}
	string str;
	cout<<"enter prefix string\n";
	cin>>str;
	cout<<countPrefix(root,str)<<"\n";
	
	
	return 0;
}

