#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	long long int num;
	int test;
	
	vector<int>v;
	int f=0,s=1,r;
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	for(int i=1;i<65;i++)
	{
		r=(f+s)%10;
		f=s;
		s=r;
		v.push_back(r);
	}
	//for(int i=1;i<65;i++)
		//cout<<i<<" "<<v[i]<<endl;
	cin>>test;
	while(test--)
	{
		cin>>num;
		
			cout<<v[num%60]<<endl;
	}
}