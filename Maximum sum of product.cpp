/*Sushil Kumar Singh */
#include <cassert>
#include <cctype>
#include <cfloat>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
#include <ext/numeric>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/algorithm>

using namespace std;
using namespace __gnu_cxx;

#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define ii pair<int,int>
#define vs vector<string>
#define all(v) (v).begin(), (v).end()
#define For(i,x) for(int i=0;i<x;i++)

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	vector<int>v;
	int test;
	cin>>test;
	while(test--)
	{
		v.clear();	
	int n;
	cin>>n;
	v.push_back(1);
	v.push_back(2);
	if(n==1)
		cout<<1<<endl;
	else if(n==2)
		cout<<2<<endl;
	else
	{
	int maxsum=2;
	for(int i=3;i<=n;i++)
	{
		vector<int>:: iterator it=v.begin();
		int temp=maxsum+i*v[0];
		int k=0;
		for(int j=0; j<v.size()-1;j++)
		{
			
		
		//			cout<<j<<" "<<v.size()-1<<" "<<temp<<endl;
			int newsum=maxsum;
			newsum-=v[j]*v[j+1];
			newsum+=v[j]*i + i*v[j+1];
			//cout<<newsum<<endl;
			if(temp<newsum)
			{
				temp=newsum;
				k = j;
			}
		}
		//cout<<k<<"   "<<temp<<endl;
		if(temp<v[i-2]*i+maxsum)
		{
		//	cout<<"as == ";
			v.push_back(i);
			maxsum+=i*v[i-2];
		} else
		{
			v.insert(v.begin()+k+1, i);
			maxsum=temp;
		}
		for(int k=0;k<i;k++)
			cout<<v[k]<<" ";
		cout<<endl;
		
	}
	int sum=0;
		for(int k=0;k<n-1;k++)
			sum+=v[k]*v[k+1];
		cout<<sum<<endl;			
	}
	
}
    system("pause");
}

