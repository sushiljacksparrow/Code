#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

struct node
{
	int x, y;
};

char map[1000][1000];
int path[1000][1000];
int n, m;

int dfs(int i, int j, int n)
{
	stack<node>S;
	node temp, next;
	temp.x=i;
	temp.y=j;
	path[i][j]=n;
	S.push(temp);
	while(!S.empty())
	{
		
	}
	return 1;
}
int main()
{
	char ch;
	memset(map, '*', sizeof(map));
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>map[i][j];
			//scanf("%c", &ch);
			//map[i][j]=ch;
		}
	}
	
	int ret=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(map[i][j]!='*')
			{
				//cout<<i<<" "<<j<<endl;
				ret+=dfs(i,j, ret);
				
			}
		}
	}
	
	cout<<ret<<endl;
	
	return 0;
}