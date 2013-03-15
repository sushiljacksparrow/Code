#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int in[26], out[26], color[26];
int g[26][26];
int found[26];
char word[26];

bool isConnected()
{
	int i, j;
	queue<int> Q;
	for(i=0;i<26;i++)
		color[i] = (found[i]?0:2);
	for (i = 0; color[i]; ++i)
		color[i]=1;
	Q.push(i);
	while(!Q.empty())
	{
		i = Q.front(); Q.pop();
		for (int j = 0; j < 26; ++j)
		{
			if(g[i][j] || g[j][i] && !color[j])
			{
				Q.push(j);
				color[j]=1;
			}
		}
		color[i]=2;
	}

	for (i = 0; i < 26; ++i)
		if(color[i]!=2)
			return false;
	return true;
}

bool hasEularPath()
{
	if(!isConnected())
		return false;
	int i, cnt1, cnt2;
	for(i=cnt1=cnt2; i<26; i++)
	{
		if(out[i]-in[i]==1)
			cnt1++;
		else if(in[i]-out[i]==1)
			cnt2++;
		else if(in[i]!=out[i])
			return false;
	}
	if(cnt1+cnt2==0 || (cnt1==1 && cnt2==1)) return true;
	return false;
	}
}

int main()
{
	int t,u,v, len;
	cin>>t;

	while(t--)
	{
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(g, 0, sizeof(g));
		memset(found, 0, sizeof(found));

		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			scanf("%s", word);
			len = strlen(word);
			in[v=word[0]-'a']++;
			out[u=word[len-1]-'a']++;
			g[u][v] = found[u] = found[v] = 1;
		}

		if(hasEularPath())
			printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");
	}
	return 0;
}