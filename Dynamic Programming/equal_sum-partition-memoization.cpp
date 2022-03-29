//This program checks if equal sum partition of an array is possible or not
//Memoization approach

#include<iostream>
#include<cstring>
using namespace std;

int t[2000][2000];

void initialize()
{
    memset(t, -1, sizeof(t));
}

int equalSum(int arr[], int n, int sum)
{
    if(sum==0)
        return 1;
    
    if(n==0 && sum!=0)
        return 0;

    if(t[n-1][sum]!=-1)
        return t[n-1][sum];

    if(arr[n-1]>sum)
        return t[n-1][sum] = equalSum(arr, n-1, sum);

    else
        return t[n-1][sum] = equalSum(arr, n-1, sum) || equalSum(arr, n-1, sum-arr[n-1]);
}

int checkSum(int arr[], int n)
{
    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];

    if(sum%2 != 0)
        return false;
    else
        return equalSum(arr, n, sum/2);
}

int main()
{
    int arr[] = {2, 2, 2, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    initialize();
    if(checkSum(arr, n)==1)
        cout<<"Equal sum partition is possible";
    else
        cout<<"Equal sum partition is not possible";
    return 0;
}