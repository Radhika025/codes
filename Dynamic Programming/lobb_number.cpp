//L((m+n)in subscript) counts the number of ways that m+n open paranthese can be arranged to form the start of a valid sequence of balanced
//paranthese, where n>=m>=0. 

#include<iostream>
using namespace std;

int binomial(int n, int k)
{
    int dp[n+1][k+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=min(i, k); j++)
        {
            if(j==0 || j==i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    // for(int i=0; i<=n; i++)
    // {
    //     for(int j=0; j<=k; j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[n][k];
}

int lobb(int n, int m)
{
    int res = ((2*m + 1) * binomial(2*n, m+n)) / (m+n+1);
    return res;
}

int main()
{
    int m, n;
    cout<<"Enter two numbers ";
    cin>>n>>m;
    cout<<lobb(n, m)<<endl;
    return 0;
}