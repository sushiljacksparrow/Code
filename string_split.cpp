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

const int len = 100;
string dict[] = {"this", "is", "saw", "awesome", "some", "a"};

bool searchdict(string str)
{
	int size = sizeof(dict)/sizeof(dict[0]);
	if(find(dict, dict+size, str) != dict+size)
		return true;
	return false;
}

void printwords(bool dict[][len], bool word[][len], vector< vector<int> > path, string t, int beg, int end)
{

	if(end==0)
		return;
	int k = path[beg][end];
	
	if(dict[beg][k])
		cout<<" "<<t.substr(beg, k-beg+1)<<" ";
	else
		printwords(dict, word, path, t, beg, k);
	if(dict[k+1][end])
		cout<<" "<<t.substr(k+1, end-k)<<" ";
	else
		printwords(dict, word, path, t, k+1, end);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	string text = "thisisawesomea";
	//cin>>text;
	bool word[len][len] = {false};
	bool dict[len][len] = {false};
	
	int n = text.size();
	vector< vector<int> > path(n, vector<int>(n, -1));
	
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			string sub = text.substr(i,j-i+1);
			dict[i][j]=searchdict(sub);
			if(dict[i][j])
				path[i][j]=i;
		}
	}
	
	for(int i=0;i<n;i++)
		word[i][i]=dict[i][i];
	
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<=n-l;i++)
		{
			int j=i+l-1;
			word[i][j]=dict[i][j];
			for(int k=i;k<j;k++)
			{
				if(word[i][k] && word[k+1][j])
				{
					word[i][j]=true;
					path[i][j]=k;
				}
			}
		}
	}
	
	if ( word [0][n-1] == false ) 
                cout << "no paritioning is possible" << endl;
        else if ( dict [0][n-1] ) 
                cout << text << endl;
        else 
                printwords (dict, word, path, text, 0, n-1);
    cout<<endl;
 
    system("pause");
}

