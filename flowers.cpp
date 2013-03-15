/* Sample program illustrating input/output */
#include<iostream>
#include<algorithm>
using namespace std;
int main(){

 

//Helpers for input and output

	int N, K;
	int C[102];

	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> C[i];
	}
	int sum=0;
	sort(C, C+N);
	int turn = N/K;
	if(N%K!=0)
		turn++;
//	cout<<turn<<endl;
	int flower=N-1;
	

		for(int j=1;j<=turn && flower>=0;j++)
		{
			for(int i=0;i<K && flower>=0;i++)
			{
				//cout<<C[flower]*j<<" ";
				sum+=C[flower]*j;
				flower--;
			}
		}
	cout<<sum<<endl;	
	system("pause");
}
