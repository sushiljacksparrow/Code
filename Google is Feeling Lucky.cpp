#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector> 
#include<algorithm>
using namespace std;

struct ps
	{
		int t;
		string s;
		bool operator<(struct ps p) const
		{
			if (t != p.t) return t<p.t;
			else return false;
		}
	};

vector<struct ps> v;
 int main()
     {
	int t,b,x=1, mx;
	char tmp[200];
	string s,t_1;
	for(scanf("%d\n",&t) ; t>0 ; t--)	
	{
		v.clear();
		for(int i=0;i<10;i++) 
		 {
			getline(cin , s) ;
			sscanf(s.c_str(),"%s %d",tmp , &b);
			t_1 = string( tmp );
			//cout<<t_1<<"-- "<<b<<endl;
			v.push_back((struct ps){ b , t_1 });
		 }
		sort(v.rbegin() , v.rend());		
		mx=v[0].t;
		printf("Case #%d:\n",x++);
		for(int i=0;i<10;i++)
		{
			if(v[i].t == mx ) cout<<v[i].s<<endl;
			else break;
		}
		 
	}
     }

