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
	
	int n,t;
	cin>>n;
 	vector<int>input;
 	for(int i=0;i<n;i++)
	{
	    cin>>t;
	    input.push_back(t);
	}
	int current_sum=input[0];
	int max_sum=0, current_start=0, current_end=0;
	int start, end;	
	for(int i=0;i<n;i++)
	{
	 		if(current_sum>max_sum)
	 		{
			 	max_sum=current_sum;
				start=current_start;
				end=current_end;
           }
		   if(current_sum<0)
		   {
		   		current_sum=input[i];
				current_start=i;
				current_end=i;
				continue;
	       }
	       current_sum+=input[i];
	       current_end=i;
    }
				   			 				   
    cout<<max_sum<<" "<<start<<" "<<end<<endl;											   
    system("pause");
}

