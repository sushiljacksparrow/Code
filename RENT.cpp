#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct node {
       int st,fin,gain;
       bool operator<( const node & ob ) const {
            return fin < ob.fin;
       }
};
int main()
{
    int test,n;
    node temp;
    cin>>test;
    while( test-- )
    {
           cin>>n;
           vector<node>vn(n);
           for( int i=0;i<n;i++ )
           {
                cin>>vn[i].st>>vn[i].fin>>vn[i].gain;
                vn[i].fin+=vn[i].st;
           }
           
           sort(vn.begin(), vn.end());
           int dp[n+1];
           memset(dp,sizeof(dp),0);
           dp[0] = vn[0].gain;
           
           for( int i=1;i<n;i++)
           {
              temp.fin = vn[i].st;
              int j= (int)(upper_bound(vn.begin(), vn.begin()+i, temp)-vn.begin());  
              j-=1;
              if( j==-1 )
              {
                   dp[i] = vn[i].gain;
              }
              else
              {
                  dp[i] = dp[j] + vn[i].gain;
              }
              dp[i] = max( dp[i-1], dp[i] );
           }
           
           cout<<dp[n-1]<<endl;
    }
    
    system("pause");
}

