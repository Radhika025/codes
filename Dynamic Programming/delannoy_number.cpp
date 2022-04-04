#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int m, n;
    cout<<"Delannoy Number\nEnter n : ";
    cin>>n;
    cout<<"Enter m : ";
    cin>>m;

    int dp[m+1][n+1];

    for(int i=0; i<=m; i++)
        dp[i][0] = 1;
    
    for(int i=0; i<=n; i++)
        dp[0][i] = 1;

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i][j-1];
        }
    }

    cout<<dp[m][n];
    return 0;
}