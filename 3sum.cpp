#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
class Solution {
public:
    
    int search(int val, vector<int> num, int s)
    {
        int e=num.size();
        int mid;
        while(s<e)
        {
            mid=(s+e)/2;
            if(num[mid]==val)
                return mid;
            else if(num[mid]>val)
                e=mid-1;
            else
                s=mid+1;
        }
        return -1;
    }
    vector<vector<int> > threeSum(vector<int> &num) 
    {
        sort(num.begin(), num.end());
        vector< vector<int> > ret;
        for(int i=0;i<num.size()-2;i++)
        {
            for(int j=i+1;j<num.size()-1;j++)
            {
                int required = num[i]+num[j];
                int index=search(-1*required, num, j+1);
                if(index!=-1)
                {
                    vector<int>temp;
                    temp.push_back(num[i]);
                    temp.push_back(num[j]);
                    temp.push_back(num[index]);
                    ret.push_back(temp);
                }
            }
        }
        return ret;
        
    }
};
