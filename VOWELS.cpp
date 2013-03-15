#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	char ch;
	int ret=0;
	
	
	while((ch=getchar())!='\n')
	{
		
		ch=tolower(ch);
		if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
		{
			ret++;
			//cout<<ch<<" "<<ret<<endl;
		}
	}
	printf("%d\n", ret);
	return 0;
	//system("pause");
}