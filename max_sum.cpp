#include<iostream>
#include<cmath>

#define INT_MIN -1
using namespace std;

int max_sum(int arr[], int len, int &start, int &end)
{
	int current_start=0, current_end=0, current_sum=0;
	int current_max=INT_MIN;
	
	current_sum=arr[0];
	
	for(int i=0;i<len;i++)
	{
		if(current_sum>current_max)
		{
			current_max=current_sum;
			start=current_start;
			end=current_end;
		}
		
		if(current_sum<0)
		{
			current_start=i;
			current_end=i;
			current_sum=arr[i];
			continue;
		}
		
		current_sum+=arr[i];
		current_end=i;
	}

	return current_max;
}

int main()
{
  int A[] = {1, 3, -8, 2, -1, 10, -2, 1 };
  int B[] = {0, 0, -1, -2, -3 };
 
  int max, start, end;
   
  max = max_sum(A, 8, start, end);
  cout << "A : max = " << max << ",  start = "
       << start << " end = " << end << endl;
    
  max = max_sum(B, 5, start, end);
  cout << "B : max = " << max << ",  start = "
       << start << " end = " << end << endl;
	   
	system("pause");
}
