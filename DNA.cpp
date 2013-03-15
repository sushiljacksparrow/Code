#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class DNAString {
public:
	int minChanges(int maxPeriod, vector <string> dna) 
	{
		int len=dna.size();
		
		int changes=INT_MAX;
		for(int i=maxPeriod;i>=1;i--)
		{
			int count=0;
			for(int k=1;k<=len/i;k++)
			{
				cout<<"das";
				for(int j=0;j<maxPeriod;j++)
				{
					cout<<i<<" "<<k<<" "<<j<<endl;
					if(dna[j]!=dna[j+i*k])
						count++;
				}
			}
			cout<<i<<" "<<count<<endl;
			changes=min(changes, count);
		}
		return changes;
	}
};



int main()
{
	DNAString dna = new DNAString();
	dna.minChanges("ATAGATA");
	system("pause");
}
