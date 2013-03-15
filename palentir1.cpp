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

char arr[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
	                  'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	                  
long long base_converter(string str)
{
	string base = str.substr(str.find('_')+1);
	string number = str.substr(0, str.find('_'));

	int num = 0;
	for(int i=0;i<base.size();i++) { num = num*10 + base[i]-'0'; }
	long long ret = 0;
	double ind = 0;

	for(int i=number.size()-1;i>=0;i--)
	{
		for(int j=0;j<36;j++)
		{
			if(number[i] == arr[j])
			{
				ret += j * pow(num, ind++);
				break;
			}
		}
	}		
	cout<<str<<" "<<base<<" "<<num<<" "<<number<<" "<<ret<<endl;
	return ret;	
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	string str, t;
	getline(cin, str);
	
	vector<char>operators;
	vector<long long>numbers;
	
	stringstream ss(str);
	while(ss>>t)
	{
		numbers.push_back(base_converter(t));
		ss>>t;
		operators.push_back(t[0]);
	}
	int len = operators.size();
	long long ans = 0;
	for(int i=0;i<len;i++)
	{
		if(operators[i]=='*')
		{
			numbers[i] *= numbers[i+1];	
			numbers[i+1] =0;
		}
	}
	
    system("pause");
}

