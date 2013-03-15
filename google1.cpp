#include<iostream>
#include<vector>
#include<queue>
#define pb push_back
#define pp pair<int,int>
#define ppp pair<pair<int,int>,int>
#define f first
#define s second

using namespace std;


bool dp[40001][7];
int main()
{

	int a,b,c;

	int t;
	cin>>t;
	while(t--)
	{
        cin>>a>>b>>c;
        //cout<<a<<"  "<<b<<"  "<<c<<endl;
        if ( c >a && c>b) {cout<<"-1"<<endl;continue;}
        else if(c==a || c==b) {cout<<"1"<<endl;continue;}
        else if (c==0){cout<<"0"<<endl;continue;}

        memset(dp,0,sizeof(dp));

        queue<pp>q;
        pp p;
        p.f=a;
        p.s=b;
        q.push(p);
        queue<int>q1;
        int count=0;
        //int countb=0;
        q1.push(count);
        bool solution=0;
                while(q.empty() == false){
                        pp p = q.front();
                        q.pop();
                        int uu = q1.front();

                        q1.pop();
                        //if(counta==0)countb++;

                        int index2,index1;
                        if (p.f ==0&&p.s==0){
                                index2=0;index1=p.f;
                        }else if(p.f==0&&p.s!=0){
                                index2=1;index1=p.s;
                        } else if(p.f==a&&p.s==0){
                                index2=2;index1=p.f;
                        }else if (p.f==a && p.s!=0){
                                index2=3;index1=p.s;
                        } else if(p.s==0 && p.f!=0){
                                index2=4;index1=p.f;
                        } else if(p.s==b && p.f==0){
                                index2=5;index1=p.s;
                        } else if(p.s==b && p.f!=0){
                                index2=6;index1=p.f;
                        }
                        //cout<<p.f<<"  "<<p.s<<"  npow "<<index1<<"   "<<index2<<" "<<dp[index1][index2]<<endl;

                        if (dp[index1][index2] == 1)continue;
                        dp[index1][index2]=1;

                        if (p.f==c || p.s==c) {
                                cout<<uu<<endl;solution=1;break;
                        }

                        pp t;
                        uu++;
                        if (p.s <b){
                        //      cout<<"CON1  ";
                                t.f=max(p.f-b+p.s,0);
                                t.s=min(b,p.s+p.f);
                        //      cout<<t.f<<"  "<<t.s<<endl;
                                q.push(t);
                                q1.push(uu);
                                t.s=b;
                                t.f=p.f;
                                q.push(t);
                                q1.push(uu);

                        }
                        if (p.f<a){
                //      cout<<"CON2"<<endl;
                                t.s=max(p.s-a+p.f,0);
                                t.f=min(a,p.f+p.s);
                                q.push(t);
                                q1.push(uu);
                                t.f=a;
                                t.s=p.s;
                                q.push(t);
                                q1.push(uu);
                        }
                        t.f=0;
                        t.s=p.s;
                        q.push(t);
                        q1.push(uu);
                        t.f=p.f;
                        t.s=0;
                        q.push(t);
                        q1.push(uu);

                }
                if (!solution){
                        cout<<"-1"<<endl;continue;
                }
        }

 return 0;

}
