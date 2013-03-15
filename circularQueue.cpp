#include<iostream>
#include<string>
#include<cmath>

using namespace std;

void print_all_substrings_iterative(const std::string& str)
{
    const size_t size = str.size();
    for (size_t i = 1; i < std::pow(2.0, (double)size); ++i) {
        for (size_t j = 0; j < size; ++j) {
            if (i & (1 << j)) {
                std::cout << str[j];
            }
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}


int number_of_binary(int n)
{
	int count=0;
	while(n>0)
	{
		if(n%2==1)
			count++;
		n/=2;
	}
	return count;
}
int main()
{
	cout<<number_of_binary(13);
	return 0;
}


