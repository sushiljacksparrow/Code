#include<iostream>
#include<pair>
#include<algorithm>
#include<vector>


using namespace std;

bool cmp(pair<int, ch> &p1, pair<int, ch> &p2)
{
	if(p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first < p2.first;
}

int overlap(int arr[][2], int n)
{
	int count = 0;
	vector< pair<int, ch> > vp;
	pair<int, ch>p;
	for(int i=0;i<n;i++)
	{
		p.first = arr[i][0];
		p.second='s';
		vp.push_back(p);
		p.first=arr[i][1];
		p.second='e';
		vp.push_back(p);
	}
	
	sort(vp.begin(), vp.end(), cmp);
	int max_so_far = 0;
	
	for(int i=0;i<vp.size();i++)
	{
		if(vp[i].second=='s')
			count++;
		else 
			count--;
		max_so_far = max(max_so_far, count);
	}
	cout<<max_so_far<<endl;
int main()
{
	system("pause");
}