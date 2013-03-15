/*Sushil Kumar Singh */

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


int ans[100][2];
struct balance
{
	int weight;
	int lweight, rweight;
	vector<int>left;
	vector<int>right;
};

vector<balance>g;

int solve(int bal)
{
	if(g[bal].weight>=0)
		return g[bal].weight;
		
	int lwet=g[bal].lweight;
	int rwet=g[bal].rweight;
	
	for(int i=0;i<g[bal].left.size();i++)
		lwet+=solve(g[bal].left[i]);
	for(int j=0;j<g[bal].right.size();j++)
		rwet+=solve(g[bal].right[j]);
	
	//cout<<bal<<" "<<lwet<<" "<<rwet<<endl;
	if(lwet>rwet)
		ans[bal][1]=lwet-rwet;
	else if(rwet>lwet)
		ans[bal][0]=rwet-lwet;
		
	//ans[bal][0]=lwet-g[bal].lweight;	
	//ans[bal][1]=rwet-g[bal].rweight;
	g[bal].weight = max(lwet, rwet)*2+10;
	
	return g[bal].weight;
}

void printG()
{
	int n=g.size();
	for(int i=0;i<n;i++)
	{
		cout<<"bal "<<i<<endl;
		cout<<g[i].lweight<<" "<<g[i].rweight<<endl;
		for(int j=0;j<g[i].left.size();j++)
			cout<<g[i].left[j]<<" ";
		cout<<endl;
		for(int j=0;j<g[i].right.size();j++)
			cout<<g[i].right[j]<<" ";
		cout<<endl<<endl;
		
	}
}

int main()
{
    //freopen("inout.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	
	
	int n, val;
	vector<int>other;
	char linput[1000];
	char rinput[1000];
	
	balance bal;
	scanf("%d", &n);
	
	cin.getline(linput, 1000);
	for(int i=0;i<n;i++)
	{
		//cout<<"dasdasd\n";
		cin.getline(linput, 1000);
		bal.weight = -1;
		stringstream ss1(linput);
		ss1>>val;	
		bal.lweight = val;
		other.clear();
		while(ss1>>val)
		{
			//cout<<val<<" ";
			other.push_back(val);
		}
		//for(int j=0;j<other.size();j++)
		//	cout<<other[j]<<" ";
		//cout<<endl;
		
		bal.left = other;
		
		other.clear();
		
		cin.getline(rinput, 1000);		
		stringstream ss2(rinput);
		ss2>>val;
		bal.rweight = val;
		while(ss2>>val)
		{
			//cout<<val<<" ";
			other.push_back(val);
		}
		bal.right = other;
		//for(int j=0;j<other.size();j++)
		//	cout<<other[j]<<" ";
		//cout<<endl;
		
		g.push_back(bal);
	}
	//printG();
	solve(0);
	for(int i=0;i<n;i++)
		cout<<i<<": "<<ans[i][0]<<" "<<ans[i][1]<<endl;

    system("pause");
}

