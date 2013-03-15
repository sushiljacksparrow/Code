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


int *memory[4][1001];
int num, res;

char *sum(char *a, char *b)
{
     int lena = strlen(a);
     int lenb = strlen(b);
     int m=max(lena, lenb);
     char *res = (char *)malloc(m+2);
     for(int i=0;i<=m;i++)
             res[i]='0';
     res[m+1]='\0';
     int t=0;
     for(int i=lena-1, j=lenb-1, k=m; i>=0 || j>=0; i--, j--, k--)
     {
             
             if(i>=0 && j>=0)
             {
                    t=a[i]-'0' + b[j]-'0';
             } else if(i>=0)
             {
                    t=a[i]-'0';
             } else 
             {
                    t=b[j]-'0';
             }
             res[k]=(t%10)+'0';
             if(t<10)
             {
                      t=0;
             } else if(t<20)
             {
                    t=1;
             } else
             {
                   t=2;
             }
     }
     if(t>0)
            res[0]=(t%10)+'0';
     char *newres = (char*)malloc(m+2);
     int index=0;
     for(int i=0;i<=m;i++)
     {
             if(res[i]!='0')
             {
                            index=i;
             }
     }
     cout<<index<<" "<<res<<endl;
     for(int i=0;i<=m;i++)
     {
             newres[i]=res[index+i];
     }
     newres[m-index-1]='\0';
     printf("sum %s: of %s, %s", newres, a, b);
     return res;
}
               
                     
                      
     
void solve(char *number, int digits)
{
    if(digits>num)
    {
              return;
    }
    if(digits == num)
    {
              //printf("%s\n", number);
              res++;
              return;
    }
    
    if(number[digits-1] == '1') 
    {
                     number[digits]='3';
                     number[digits+1]='\0';
                     solve(number, digits+1);
    } else if(number[digits-1] == '3') 
    {
                     number[digits]='1';
                     number[digits+1]='\0';       
                     solve(number, digits+1);              
                     number[digits]='5';
                     solve(number, digits+1);
    } else if(number[digits-1] == '5')
    {
                     number[digits]='7';
                     number[digits+1]='\0';       
                     solve(number, digits+1);
    } else if(number[digits-1]=='7')
    {
                     number[digits]='5';
                     number[digits+1]='\0';
                     solve(number, digits+1);       
                     number[digits]='3';
                     solve(number, digits+1);
    }
}
                     
    
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test;
    scanf("%d", &test);
    
    while(test--)
    {
                 sum("99", "9");
                 scanf("%d", &num);
                 res=0;
                 char *number = (char*)malloc(100000);
                 number[1]='\0';
                 number[0]='1';
                 solve(number, 1);
                 number[0]='3';
                 solve(number, 1);
                 number[0]='5';
                 solve(number, 1);
                 number[0]='7';
                 solve(number, 1);
                 printf("%d\n", res);
    }
    system("pause");
}

