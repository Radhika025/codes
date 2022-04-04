#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n, m;
    cout<<"Eulerian Number\nEnter n : ";
    cin>>n;
    cout<<"Enter m : ";
    cin>>m;
    
    int dp[n+1][m+1];

    memset(dp, 0, sizeof(dp));
    
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i>j)
            {
                if(j==0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = ((i-j) * dp[i-1][j-1]) + ((j+1) * dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}