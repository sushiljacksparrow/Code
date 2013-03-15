#include<iostream>

using namespace std;

struct node
{
	vector<node*>neighbours;
};

node *clone_graph(node *root)
{
	if(root==NULL)
		return NULL;
	map<node*, node*>mapp;
	node *clone = newnode(root);
	mapp[root]=clone;
	queue<node*>Q;
	Q.push(root);
	
	while(!Q.empty())
	{
		node *actual = Q.front();
		Q.pop();
		
		int n= actual->neighbours();
		for(int i=0;i<n;i++)
		{
			node *neighbour = neighbours[i];
			if(mapp[neighbour]==mapp.end())
			{
				node *temp = newnode(neighbour);
				mapp[actual]->neighbours.push_back(temp);
				mapp[neighbour]=temp;
				Q.push(temp);
			} else
			{
				mapp[actual]->neighbours.push_back(mapp[neighbour]);
			}
		}
	}
	return clone;
}
		
				
int main()
{
	system("pause");
}