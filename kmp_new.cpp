#include<iostream>
#include<string>

using namespace std;

void failure_function(int arr[], string str, int n)
{
	arr[0]=0;
	int len=0, i=1;
	while(i<n)
	{
		if(str[i]==str[len])
		{
			len++;
			arr[i]=len;
			i++;
		} else
		{
			if(len!=0)
			{
				len = arr[len-1];
			} else
			{
				arr[i]=0;
				i++;
			}
		}
	}
}


void KMP(string pattern, string text)
{
	int plen = pattern.size();
	int tlen = text.size();
	
	int arr[plen];
	failure_function(arr, pattern, plen);

	int p=0, t=0;
	
	while(t<tlen)
	{
		if(pattern[p]==text[t])
		{
			p++;
			t++;
		}
		if(p==plen)
		{
			cout<<"Pattern found at " << t-p+1<<endl;
			p = arr[p-1];
		}

		if(pattern[p]!=text[t])
		{
			if(p!=0)
			{
				p = arr[p-1];
			} else
			{
				t++;
			}
		}	
	}
}

int main()
{
	string text = "oneonone";
	string pattern = "one";
	KMP(pattern, text);
	system("pause");
}

		
