#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class WordsGame {
public:
	int solve(string a, string b)
	{
		string s_a = a, s_b = b; 
		sort(s_a.begin(), s_a.end()); 
		sort(s_b.begin(), s_b.end());
		if(s_a!=s_b) return INT_MAX;
		int count = 0;
		for(int iter=0;iter<b.size();iter++)
		{
			for(int i=0;i<a.size();i++)
				if(b[i] != a[i])
				{
					int f = a.find(b[i]);
					swap(a[f], a[i]);
					count++;
				}
		}
		return count;
	}
	
	int minimumSwaps(vector <string> grid, string word)
	{
		int ret = INT_MAX;
		for(int i=0;i<grid.size();i++) ret = min(ret, solve(grid[i], word));	
		for(int i=0;i<grid[0].size();i++)
		{
			string t = "";
			for(int j=0;j<grid.size();j++) t+=grid[i][j];
			ret = min(ret, solve(t, word));
		}
		return ret != INT_MAX ? ret: -1;
	}
};


