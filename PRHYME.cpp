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

#define INF (1<<30)

vector<string>wordlist;
map<string, int> m;
struct node
{
	int word, prefix;
	int small1, small2;
	node *child[26];
};

node *initialize()
{
	node *temp = (node*)malloc(sizeof(node));
	temp->word = temp->prefix = 0;
	temp->small1 = temp->small2 = INF;
	for(int i=0;i<26;i++)
		temp->child[i]=NULL;
	return temp;
}

void addword(string word, int pos, node *vertex, int order)
{
	//cout<<word<<" "<<pos<<endl;
	if(pos==-1)
	{
		if(order < vertex->small1)
		{
			vertex->small2=vertex->small1;
			vertex->small1=order;
		} else if(order < vertex->small2)
		{
			vertex->small2 = order;
		}
		
		vertex->word++;
		vertex->prefix++;
	} else 
	{
		int k=word[pos]-'a';
		if(order < vertex->small1)
		{
			vertex->small2=vertex->small1;
			vertex->small1=order;
		} else if(order < vertex->small2)
		{
			vertex->small2 = order;
		}
		
		vertex->prefix++;
		if(vertex->child[k]!=NULL)
			addword(word, pos-1, vertex->child[k], order);
		else
		{
			vertex->child[k]=initialize();
			addword(word, pos-1, vertex->child[k], order);
		}
	}
}

node *findstart(string word, node *vertex, int pos, int flag)
{
	if(pos<0)
		return vertex;
	int k=word[pos]-'a';
	if(vertex->child[k]!=NULL && vertex->child[k]->prefix >= flag)
		return findstart(word, vertex->child[k], pos-1, flag);
	else
		return vertex;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	 string word;
     node *root=initialize();
     while(getline(cin,word))
     {
                    int len=word.length();
                    if(len==0 || word[0]==' ') break;
                    wordlist.push_back(word);
     }
     sort(wordlist.begin(), wordlist.end());
     int sz=wordlist.size();
	
	
	for(int i=0;i<sz;i++)
	{
		m[wordlist[i]]=i+1;
		addword(wordlist[i], wordlist[i].size()-1, root, i);
	}
	
	while(getline(cin, word))
	{
		int len=word.size();
		int flag=1, order = INF;
		if(m[word])
		{
			flag=2;
			order=m[word]-1;
		}
		node *p = findstart(word, root, len-1, flag);
		if(order!=p->small1)
			cout<<wordlist[p->small1]<<endl;
		else
			cout<<wordlist[p->small2]<<endl;
	}	
			
    system("pause");
}

