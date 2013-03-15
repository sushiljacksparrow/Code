#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a[100010], N;
int b[100010], K;
int inc[100010];
int decr[100010];

int main()
{
	for(int cs=0;cs<10 && scanf("%d", &N) == 1 && N>0; cs++)
	{
			for(int i=0;i<N;i++)
				scanf("%d", &a[i]);
			
			K=0;
			for(int i=0;i<N;i++)
			{
				int left = -1, right = K;
				while(right-left>1)
				{
					int mid = (left+right)/2;
					if(b[mid]>a[i])
						right = mid;
					else
						left = mid;
				}
				inc[i]=right+1;
				b[right]=a[i];
				if(right==K) K++;
			}
			for(int i=0;i<N;i++)
				printf("%d ", a[i]);
			printf("\n");
			for(int i=0;i<N;i++)
				printf("%d ", inc[i]);
			printf("\n");
			K=0;
			for(int i=N-1;i>=0;i--)
			{
				int left = -1, right = K;
				while(right-left>1)
				{
					int mid = (left+right)/2;
					if(b[mid]<a[i])
						right = mid;
					else
						left = mid;
				}
				decr[i]=right+1;
				b[right]=a[i];
				if(right==K) K++;
			}
			int len = inc[0];
			for(int i=1;i<N;i++)
				len = max(len, inc[i]);
			
			vector<int>output;
			for(int i=0;i<N;i++)
				if(inc[i]+decr[i]-1==len)
					output.push_back(a[i]);
			sort(output.begin(), output.end());
			printf("%d\n", output.size());
			for(int i=0;i<output.size();i++)
				printf(i==0?"%d":" %d", output[i]);
			printf("\n");
	}
	return 0;
}
