#include<iostream>

using namespace std;
int INT_MIN = 999999;
int INT_MAX = 999999;
int main()
{
	int coin[4]={1, 3, 4, 5};
	int ret[100];
	int sum;
	while(cin>>sum)
	{
		memset(ret, INT_MAX, sizeof(ret));
		ret[0]=0;
		for(int i=1;i<=sum;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(i-coin[j]>=0)
				{
					ret[i]=(ret[i-coin[j]]+1) > ret[i] ? ret[i] : ret[i-coin[j]]+1;
				}
			}
		}
		cout<<ret[sum]<<endl;
	}
}
		
		