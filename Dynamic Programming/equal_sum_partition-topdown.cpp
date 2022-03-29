//This program checks if equal sum partition of an array is possible or not
//Top-down approach

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int arr[] = {2, 2, 2, 7, 7, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];

    if(sum%2 != 0)
    {
        cout<<"Equal sum partition not possible (sum of numbers if odd)";
        return 0;
    }
    else
    {
        sum = sum/2;
        int t[n+1][sum+1];

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

        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<sum+1; j++)
            {
                if(arr[i-1]>j)
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
            }
        }

        if(t[n][sum] == 1)
            cout<<"Equal sum partition is possible";
        else    
            cout<<"Equal sum partition is not possible";
    }
    return 0;
}