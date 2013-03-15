#include <iostream>
#include<string>

using namespace std;

int getMinimum(string s, int oCost, int xCost)
{
	int len = s.size()-1;
	int res = 0;
	int i=0, j = len-1;
	while(j>i)
	{
		if(s[i]=='?' && s[j]=='?')
			res = 2*min(oCost, xCost), i++, j--;
		else if(s[i]=='o' && s[j]=='?')
			res+=oCost, i++, j--;
		else if(s[i]=='x' && s[j]=='?')
			res+=xCost, i++, j--;
		else if(s[i]=='?' && s[j]=='o')
			res+=oCost, i++, j--;
		else if(s[i]=='?' && s[j]=='x')
			res+=xCost, i++, j--;
		else if(s[i]==s[j])
			i++, j--;
		else
			return -1;
	}
	return res;
}

int main()
{
	cout<<getMinimum("xo?xox?", 3, 5)<<endl;
	system("pause");
}
