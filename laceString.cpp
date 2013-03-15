#include<iostream>
#include<string>

using namespace std;


string laceString(string s1, string s2)
{
	if(s1.size()==0)
		return s2;
	if(s2.size()==0)
		return s1;
	return s1.substr(0,1)+s2.substr(0,1)+laceString(s1.substr(1), s2.substr(1));
}
int main()
{
	string s1, s2;
	while(cin>>s1>>s2)
		cout<<laceString(s1, s2)<<endl;
	system("pause");
}