#include<iostream>
#include<vector>
using namespace std;

int coinchange(vector <int>& a, int v, int n, vector<vector<int>>& dp)
{
    if(v==0)
        return dp[n][v]=1;
    if(n==0)
        return 0;
    if(dp[n][v]!=-1)
        return dp[n][v];
    if(a[n-1]<=v)
        return dp[n][v] = coinchange(a, v-a[n-1], n, dp) + coinchange(a, v, n-1, dp);
    else
        return dp[n][v] = coinchange(a, v, n-1, dp);
}

int main()
{
    int n, v;
    n = 4, v = 10;
    vector <int> a = {2,5,3,6};
    vector<vector<int>> dp(n+1, vector<int> (v+1, -1));
    int res = coinchange(a, v, n, dp);
    cout<<res<<endl;
    return 0;
}