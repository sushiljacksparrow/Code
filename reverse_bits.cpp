#include<iostream>

using namespace std;


int maxLen(string str)
{
	int n = str.size();
	int i=0, j=0;
	int mem[256]={0};
	int ret=1;
	while(j<n)
	{
		if(mem[str[j]])
		{
			ret=max(ret, j-i);
			while(str[i]!=str[j])
			{
				mem[str[i]]=0;
				i++;
			}
			i++;
		} else
		{
			mem[str[j]]=1;
		}
		j++;
	}
	ret=max(ret, n-i);
	return ret;
}


int swap_bits(unsigned int n, unsigned int i, unsigned int j)
{
	int l = ((n>>i)&1);
	int h = ((n>>j)&1);
	if(l^h)
		n ^= ((1U<<i)|(1U<<j));
	return n;
}

int main()
{
	unsigned int n;
	cin>>n;
	int size = sizeof(n)*8;
	cout<<size<<endl;
	for(unsigned int i=0;i<size/2;i++)
		n = swap_bits(n, i, size-i-1);
	cout<<n<<endl;

	system("pause");
}
