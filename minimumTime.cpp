
int minimumTime(vector <string> grid)
{
	int n = grid.size(), m = grid[0].size();
	vector<int>dx, dy;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(grid[i][j]=='o)
			{
				dx.push_back(i);
				dy.push_back(j);
			}
	
	int count=dx.size();
	sort(dx.begin(), dx.end());
	sort(dy.begin(), dy.end());
	int ret=INT_MAX;
	
	for(int x=0;x<n;x++)
	{
		int row_cost=0;
		for(int i=0;i<count;i++)
			row_cost+=abs(dx[i]-x);
		for(int y=0;y+count<m;y++)
		{
			int col_cost=0;
			for(int i=0;i<count;i++)
				col_cost+=abs(dy[i]-(y+i));
			ret=min(ret, row_cost+col_cost);
		}
	}
	
	for(int y=0;y<m;y++)
	{
		int col_cost=0;
		for(int i=0;i<count;i++)
			col_cost+=abs(y[i]-y);
		for(int x=0;x+count<n;x++)
		{
			int row_cost=0;
			for(int i=0;i<count;i++)
				row_cost+=abs(dx[i]-(x+i));
			ret=min(ret, row_cost+col_cost);
		}
	}
	return ret;
}
		