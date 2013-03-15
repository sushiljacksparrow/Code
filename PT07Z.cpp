/* Sushil Kumar Singh */
#include <cassert>
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using namespace std;


#define FOR(a,x,y) for(int a = (x); a < (y); ++a)
#define REP(a,n) FOR(a,0,n)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
typedef long long ll;



template<class T> inline int size(const T&c) { return c.size(); }
int n;
vector< vector<int> >v;
int maxi,pt;
void dfs(int node, vector<bool> &flag, int len)
{
  if(maxi<len)
  {
             maxi=len;
             pt=node;
  }
  
  flag[node]=true;
  
  int siz=v[node].size();
  FOR(i,0,siz)
  {
             if(flag[v[node][i]]==false)
             {
                                       dfs(v[node][i],flag,len+1);
             }
  }
}  
    
    
int main()
{
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  scanf("%d",&n);
  int n1,n2;
  v.resize(n+1);
  FOR(i,0,n-1)
  {
            scanf("%d %d",&n1,&n2);
            v[n1].pb(n2);
            v[n2].pb(n1);
  }
  maxi=0;
  vector<bool>flag(n+1,false);
  dfs(1,flag,0);
  
  maxi=0;
  for(int i=0;i<=n;i++) flag[i]=false;
  
  dfs(pt,flag,0);
  cout<<maxi<<endl;
  system("pause");
}

