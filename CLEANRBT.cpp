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

struct pos
{
 	   int x, y, moves;
};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int l,w;
    char map[21][21];
	pos *current = (pos*)malloc(sizeof(pos));    

    while(cin>>l>>w)
    {
	    if(l==0 && w==0)
	    		break;
	    int visit[l][w];
	    memset(visit, 0, sizeof(visit));
	 	for(int i=0;i<l;i++)
		{
		 		for(int j=0;j<w;j++)
	 			{
				 		scanf("%c", &map[i][j]);
				 		if(map[i][j]=='o')
				 		{
					  	   current->x=i;
					  	   current->y=j;
					  	   map[i][j]='V';
					  	   current->moves=0;
					  	}
		        }
		}
		queue<pos*> Q;
		Q.push(current);
		pos *temp;
		pos *newPos = (pos*)malloc(sizeof(pos));
		int minimum=0;
		while(!Q.empty())
		{

		 		temp = Q.front();
		 		cout<<temp->x << " "<< temp->y<< " "<< temp->moves<<endl;
				Q.pop();
				bool check = false;
				for(int i=0;i<l;i++)
				{
				 		for(int j=0;j<w;j++)
				 		{
						 	if(map[i][j]=='*')
							check = true;
				        }
				}
				if(check == false)
				{
				 		 minimum = temp->moves;
						 break;	
			    }
				if(temp->x-1>=0 && map[temp->x-1][temp->y]!='V')
				{
				 	newPos->x=temp->x-1;
				 	newPos->y=temp->y;
				 	newPos->moves = temp->moves+1;
				 	map[temp->x-1][temp->y]='V';
				 	Q.push(newPos);
				}else if(temp->x+1<w && map[temp->x+1][temp->y]!='V')
				{
				 	newPos->x=temp->x+1;
				 	newPos->y=temp->y;
				 	newPos->moves = temp->moves+1;
				 	map[temp->x+1][temp->y]='V';
				 	Q.push(newPos);
				}else if(temp->y+1<w && map[temp->x][temp->y+1]!='V')
				{
				 	newPos->x=temp->x;
				 	newPos->y=temp->y+1;
				 	newPos->moves = temp->moves+1;
				 	map[temp->x][temp->y+1]='V';
				 	Q.push(newPos);
				} else if(temp->y-1>=0 && map[temp->x][temp->y-1]!='V')
				{
				 	newPos->x=temp->x;
				 	newPos->y=temp->y-1;
				 	newPos->moves = temp->moves+1;
				 	map[temp->x][temp->y-1]='V';
				 	Q.push(newPos);
				} 
		}  
				
						 		   				
		printf("%d\n", minimum);
    }	
				 				 	 		  					 				
                    

    system("pause");
}

