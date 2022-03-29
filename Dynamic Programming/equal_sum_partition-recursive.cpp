//This program checks if equal sum partition of an array is possible or not
//Recursive approach

#include<iostream>
using namespace std;

bool equalSum(int arr[], int n, int sum)
{
    if(sum==0)
        return true;
    
    if(n==0 && sum!=0)
        return false;

    if(arr[n-1]>sum)
        return equalSum(arr, n-1, sum);

    else
        return equalSum(arr, n-1, sum) || equalSum(arr, n-1, sum-arr[n-1]);
}

bool checkSum(int arr[], int n)
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
    int arr[] = {2, 8, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(checkSum(arr, n)==true)
        cout<<"Equal sum partition is possible";
    else
        cout<<"Equal sum partition is not possible";
    return 0;
}