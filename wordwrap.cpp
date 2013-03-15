#include<iostream>

using namespace std;

int print_soln(int p[], int n)
{
	int k;
	if(p[n]==1)
		k=1;
	else
		k = print_soln(p, p[n]-1)+1;
	printf ("Line number %d: From word no. %d to %d \n", k, p[n], n);
	return k;
}

void solve_word_wrap(int arr[], int words, int width)
{
	int mem[words+1][words+1];
	int lc[words+1][words+1];
	int p[words+1];
	int dp[words+1];
	
	for(int i=1;i<=words;i++)
	{
		mem[i][i]=width-arr[i-1];
		for(int j=i+1;j<=words;j++)
			mem[i][j]=mem[i][j-1]-arr[j-1]-1;
	}

	for(int i=1;i<=words;i++)
		for(int j=1;j<=words;j++)
			if(mem[i][j]<0)
				lc[i][j]=INT_MAX;
			else if(j==words && mem[i][j]>=0)
				lc[i][j]=0;
			else
				lc[i][j]=mem[i][j]*mem[i][j]*mem[i][j];
	
	dp[0]=0;
	for(int j=1;j<=words;j++)
	{
		dp[j]=INT_MAX;
		for(int i=1;i<=j;i++)
		{
			if(dp[i-1]!=INT_MAX && lc[i][j]!=INT_MAX && (dp[i-1] + lc[i][j]<dp[j]))
			{
				dp[j]=dp[i-1]+lc[i][j];
				p[j]=i;
			}
		}
	}
	print_soln(p, words);
}
				
int main()
{
	int l[] = {3, 2, 2, 5};
  int n = sizeof(l)/sizeof(l[0]);
  int M = 6;
	solve_word_wrap(l, n, M);
	system("pause");
}
