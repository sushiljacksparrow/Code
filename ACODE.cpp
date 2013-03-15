#include<iostream>
#include<string>

using namespace std;


char S[5001];
long long dp[5001];
int n;

long long solve(int i)
{
	if(S[i]=='0')
		return 0;
	if(i==n)
		return 1;
	long long &ret = dp[i];
	if(ret)
		return ret;
	ret = solve(i+1);
	if(i+2<=n && ((S[i]-'0')*10 + (S[i+1]-'0'))<=26)
		ret += solve(i+2);
	return ret;
}

int main()
{
	
	while(gets(S))
	{
		if(S[0]=='0')
			return 0;
		n = strlen(S);
		memset(dp, 0, sizeof(dp));
		printf("%lld\n", solve(0));
	}
	
	system("pause");
}