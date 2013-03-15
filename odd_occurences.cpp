

void solve(int arr[], int n, int &first, int &second)
{
	int xor = arr[0];
	for(int i=1;i<n;i++)
		xor = xor ^ arr[i];
	first = 0;
	second = 0;
	int last_set_bit = xor & !(xor -1);
	
	for(int i=0;i<n;i++)
	{
		if(arr[i] && i<<last_set_bit)
		{
			first = first ^ arr[i];
		} else
		{
			second = second ^ arr[i];
		}
	}
}