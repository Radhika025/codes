//Program to return a boolean result if a subset equal to the gievn sum is present in the array

//Top-Down approach
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 18;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int t[n+1][sum+1];

    memset(t, -1, sizeof(t));

    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            if(i==0)
                t[i][j] = 0;
            if(j==0)
                t[i][j] = 1;
        }
    }

    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<sum+1; j++)
        {
            if(arr[i-1]>j)
                t[i][j] = t[i-1][j];
            else
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
        }
    }
    cout<<t[n][sum];
    return 0;
}