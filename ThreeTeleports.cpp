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

class ThreeTeleports {
public:
	int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) 
	{
	 	int res=abs(xMe-xHome)+abs(yMe-yHome);
	 	for(int k=0;k<teleports.size();k++)
	 	{
			int sx,sy,ex,ey,temp;
	 	    string tel=teleports[0];
	 	    stringstream ss(tel);
	 	    ss>>temp; sx=temp; ss>>temp; sy=temp; ss>>temp; ex=temp; ss>>temp; ey=temp;
	 	    vector<string>newteleports;
	 	    for(int i=0;i<3;i++)
	 	    		if(teleports[i]!=tel)
	 	    		   newteleports.push_back(teleports[i]);
	       
	       res=min(res, abs(xMe-sx)+abs(yMe-sy)+10+shortestDistance(ex,ey,xHome,yHome, newteleports));
	       res=min(res, abs(xMe-ex)+abs(yMe-ey)+10+shortestDistance(sx,sy,xHome,yHome, newteleports));
       }	   		
       return res;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
