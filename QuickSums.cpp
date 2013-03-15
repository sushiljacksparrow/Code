#include<iostream>
#include<cmath>

class QuickSums
{
	public:
		int target;
		int ret;
		void solve(int count, string remain, int sum)
		{
			if(remain.size()==0)
			{
				if(sum==target)
					ret=min(ret, count);
				return;
			}
			
			if(sum>target)
				return;
			
			for(int i=1;i<remain.size();i++)
			{
				int left = atoi(remain.substr(0,i).c_str());
				if(i<remain.size())
				{
					solve(count+1, remain.substr(i), sum+left);
				} else
				{
					sove(count+1, remain.substr(i), sum+left);
				}
			}
			return;
		}
					
		int minSums(string nums, int sum)
		{
			target=sum;
			solve(0, nums, sum);
			return ret;
			
		}
};