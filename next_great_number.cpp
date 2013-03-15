#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> set(int n)
{
	vector<int>ret;
	while(n>0)
	{
		ret.push_back(n%10);
		n/=10;
	}
	return ret;
}

int main()
{
	int n;
	int n1, n2;
	cin>>n1>>n2;
	
	vector<int>v1 = set(n1);
	vector<int>v2 = set(n2);
	n=v1.size();	
	
	
	bool used[100]={false};
	
	sort(v1.begin(), v1.end());
	int i=0, j=0;
	while(j<n && v2[0]>v1[j])
		j++;
	if(n==j)
	{
		cout<<"NOT POSSIBLE";
		return 0;
	}
	vector<int>ret;
	bool flag = true;
	while(j<n && v1[j]>=v2[i])
	{
		if(v1[j]>v2[i])
			flag=false;
		ret.push_back(v1[j]);
		used[j]=true;
		i++;
		j++;
	}
	
	cout<<j<<endl;
	for(int i=0;i<n;i++)
		if(used[i]==false)
			ret.push_back(v1[i]);
	for(int i=0;i<ret.size();i++)
		cout<<ret[i];
	cout<<endl;
	
	return 0;
}

	
	