// Sushil Kumar Sing IIT2006090
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cctype>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <complex>
#include <iostream>
#include <algorithm>
#include <functional>
template<class T> inline int size(const T&c) { return c.size(); }
#define all(x) (x).begin(),(x).end()
#define vs vector <string>
#define vi vector <int>
#define vvi vector < vi >
#define p(X) push_back((X))

#define fir(i,j,n) for(int (i)=(j);(i)<(n);(i)++)
#define fire(i,j,n) for(int (i)=(j);(i)<=(n);(i)++)
#define firr(i,j,n) for(int (i)=(j);(i)>(n);(i)--)
#define firre(i,j,n) for(int (i)=(j);(i)>=(n);(i)--)
#define tr(v,it) for(typeof(v.begin()) it=v.begin();it!=v.end();it++)

#define srt(v) sort((v).begin(),(v).end())
#define srtc(v) sort(v.begin(),v.end(),cmp)

#define _bc(i) __builtin_popcount(i)
#define INF 0x3f3f3f3f
#define ipow(a,b) (int)pow((double)a,(double)b)
#define fill(a,b) memset(a,b,sizeof(a))
#define maxr(num,a,b) max_element(num.begin()+a,num.begin()+b);
#define minr(num,a,b) min_element(num.begin()+a,num.begin()++b)
#define maxi(v) max_element(all(v))
#define mini(v) min_element(all(v))

using namespace std;
struct node
{
  
  int word;
  node *arr[10];
}*root;
int val;
char ch[11];
void add_word(node *t, int ind, int len)
{
     if(t->word) val=0;

     if(ind==len) {t->word=1; return;}
     else
     {
        
         int k=ch[ind]-'0';
         if(t->arr[k]==NULL)
         {
                          
           t->arr[k]=new node;
           t->arr[k]->word=0;
           for(int i=0;i<10;i++)
           t->arr[k]->arr[i]=NULL;
         }
         else
           if(ind+1==len) val=0;
         
         add_word(t->arr[k],ind+1, len);
     }
}
/*int check_prefix(node *t, string str)
{
  if(t==0) return 0;
  if(str.size()==0) return t->pre;
  else
  {
      int k=str[0]-'0';
      str.erase(0,1);
      return check_prefix(t->arr[k],str);
  }
}
int check_word(node *t, string str)
{
    
    //cout<<str<<" "<<t->word<<endl;
    if(t==NULL) return 0;
    if(str.empty()) return t->word;
    else
    {
        int k=str[0]-'0';
        str.erase(0,1);
        t=t->arr[k];
        return check_word(t,str);
    }
}*/ 
      
int main()
{
    int test;
    cin>>test;
    
    //string str;
    
    
    while(test--)
    {
         val=1;
         root=new node;
         root->word=0;
         //root->pre=0;
         for(int i=0;i<10;i++) root->arr[i]=NULL;
         int n;
         cin>>n;
         gets(ch);
         for(int i=0;i<n;i++)
         {
           
            gets(ch);
            int len=strlen(ch);
            add_word(root,0,len);
         }
         delete(root);
         if(!val) cout<<"NO\n";
         else
         cout<<"YES\n";
    }
      system("pause");
}

