#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool isPalin(string s, int b, int e)
{
	while(e>=b)
	{
		if(s[b]!=s[e])
			return true;
		b++;
		e--;
	}
	return true;
}

int main()
{
	int n, m;
	string s;
	cin>>n>>m;
	vector<string>vs(101);
	for(int i=0;i<n;i++)
		cin>>vs[i];
	
	int ret=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			string s1=vs[i], s2=vs[j];
			int b=0, e=m-1;
			while(b<=m-1 && e>=0 && s1[b]==s2[e])
				b++, e--;
			if(b>=m && e<=0)
			{
				ret=2*m;
				cout<<ret<<endl;
				return 0;
			}
			int k;
			for(k=m-1;k>=b;k--)
				if(isPalin(s1, b, k))
					break;
			ret=max(ret, 2*b+k-b+1);
			for(k=0;k<=e;k++)
				if(isPalin(s2, k, e))
					break;
			ret=max(ret, 2*e+e-k+1);
		}
	}
	cout<<ret<<endl;		
	system("pause");
}
