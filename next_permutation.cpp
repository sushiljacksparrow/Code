#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;

// A utility function two swap two characters a and b
void swap (char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

int compare (const void *a, const void * b)
{  return ( *(char *)a - *(char *)b ); }

int find_ceil(char arr[], char first, int l, int h)
{
	int ret = l;
	for(int i=l+1;i<=h;i++)
	{
		if(arr[i]>first && arr[i]<arr[ret])
			ret = i;
	}
	return ret;
}

int main()
{
	char arr[100];
	scanf("%s", arr);

	int len = strlen(arr);
	sort(arr, arr+len);
	bool finish = false;
	while(!finish)
	{
		printf("%s\n", arr);
		int i;
		for(i = len-2;i>=0;i--)
			if(arr[i] < arr[i+1])
				break;
		if(i==-1)
			finish = true;
		else
		{
			int ceil = find_ceil(arr, arr[i], i+1, len-1);
			swap( &arr[i], &arr[ceil] );
			
			qsort(arr+i+1, len-i-1, sizeof(arr[0]), compare);
		}
	}		
	system("pause");
}

