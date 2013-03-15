#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector <int> > opt;

void compute_opt(vector<int> A,int n,int hire,int fire,int sal,int max_a)
{
    // Fill all disallowed entries with infinity
    for (int i = 0; i < A[0]; ++i)
        opt[0][i] = 1000000000;
    for(int i = A[0]; i <= max_a; i++)  //for num workers in 1st month
        opt[0][i] = i*(hire + sal);

    for(int i = 1; i < n; i++)
        for(int j = 0; j <= max_a; j++)
            {
                // No need for special case handling,
                //just check all previous numbers of employees
                opt[i][j] = 1000000000;
                if (A[i] > j) continue;
                for(int k = 0; k <= max_a; k++)
                    opt[i][j] = min(opt[i][j],
                       opt[i-1][k] + j*sal + (j>k ? (j-k)*hire : (k-j)*fire));
            }   
}

int ans(vector<int> A, int n, int max_a)
{
    int ret = opt[n-1][A[n-1]];
    for(int i = A[n-1]; i <= max_a; i++)
        ret = min (ret, opt[n-1][i]);

    return ret; 
}

int main()
{
    vector<int> A;
    int n, hire, fire, sal,max_a, c = 1;
    while(1)
    {
        cin >> n;
        if(n == 0)
            break;

        A.clear();
        opt.clear();
        max_a = 0;
        cin >> hire >> sal >> fire;
        A.resize(n);
        for(int i = 0; i < n; i++)  
            {cin >> A[i];
             max_a = max(max_a,A[i]);
             }

        opt.resize(n);  
        for(int i = 0; i < n; i++)
            opt[i].resize(max_a + 2);

        compute_opt(A,n,hire,fire,sal,max_a);
        cout << "Case " << c << ", cost = $" << ans(A,n,max_a) << endl;
        c++;
    }
    system("pause");
}
