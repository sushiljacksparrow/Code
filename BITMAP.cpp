#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int a[183][183];

int main()
{
    vector<string>s;
    int test,row,col,p,q;
    cin>>test;
    string str;
    int arr[4][2]={1,0,-1,0,0,1,0,-1};
    
    while(test--)
    {
            queue<int>q1,q2;                                 
            s.clear(); 
            
            scanf("%d %d",&row,&col);
            //memset(a,500,sizeof(a));     
            for(int i=0;i<row;i++)
            {
                    cin>>str;
                    s.push_back(str);
                    
                    for(int j=0;j<col;j++)
                    if(str[j]=='1')
                    {a[i][j]=0;q1.push(i);q2.push(j);}
                    else
                    a[i][j]=500;
            }
            /*for(int i=0;i<row;i++)
            {
                    printf("%d",a[i][0]);
                    for(int j=1;j<col;j++)
                    {
                      printf(" %d",a[i][j]);
                    }
                    printf("\n");
            }*/
            while(!q1.empty())
            {
              p=q1.front(),q=q2.front();
              //cout<<p<<"  "<<q<<endl;
              q1.pop();
              q2.pop();
              int val=a[p][q]+1;
              for(int i=0;i<4;i++)
              {
                if(p+arr[i][0]>=0 && p+arr[i][0]<row && q+arr[i][1]>=0 && q+arr[i][1]<col && a[p+arr[i][0]][q+arr[i][1]]>val)
                {
                   q1.push(p+arr[i][0]);
                   q2.push(q+arr[i][1]);
                   a[p+arr[i][0]][q+arr[i][1]]=val;
                }
              }
            }
            
            for(int i=0;i<row;i++)
            {
                    printf("%d",a[i][0]);
                    for(int j=1;j<col;j++)
                    {
                      printf(" %d",a[i][j]);
                    }
                    printf("\n");
            }
    }        
       system("pause");
}
       

