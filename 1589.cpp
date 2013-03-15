#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


void func(string str)
{
	int len=str.size();
	int process[26];
	memset(process, -1, sizeof(process));
	int curr_max=0, ret=0;
	process[str[0]]=0;

	for(int i=1;i<len;i++)
	{
		if(process[str[i]-'a']==-1)
		{
			process[str[i]-'a']=i;
			curr_max++;
		} else
		{
			int last_time = process[str[i]-'a'];
			if(i-curr_max > last_time)
			{
				curr_max++;
				process[str[i]-'a']=i;
			} else
			{
				process[str[i]-'a']=i;
				if(curr_max>ret)
				{
					ret=curr_max;
				}
			}
		}
	}
	cout<<ret<<endl;
}

int main()
{
	string str;
	cin>>str;
	func(str);	
	system("pause");
}