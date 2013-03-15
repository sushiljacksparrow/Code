#include<iostream>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	int low, high;
	string str;
	set<string>ss;
	while(cin>>str)
	{
		ss.clear();
		int len = str.size();
		for(int i=0;i<len;i++)
			ss.insert(str.substr(i,1));
			
		for(int i=1;i<len;i++)
		{
			low = i-1, high = i;
			while(low>=0 && high<len && str[low]==str[high])
			{
				ss.insert(str.substr(low, high-low+1));
				low--; high++;
			}
			low = i-1, high = i+1;
			while(low>=0 && high<len && str[low]==str[high])
			{
				ss.insert(str.substr(low, high-low+1));
				low--; high++;
			}
		}
		
		cout<<"The string '"<<str<<"' contains "<<ss.size()<<" palindromes."<<endl;
	}
				
	system("pause");
}
