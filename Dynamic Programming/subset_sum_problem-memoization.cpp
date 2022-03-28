//Program to return a boolean result if a subset equal to the gievn sum is present in the array

//Memoization approach
#include<iostream>
#include<cstring>
using namespace std;

int t[1002][1002];

void initialize()
{
    memset(t, -1, sizeof(t));
}

int isSubsetSum(int arr[], int n, int sum)
{
    //base cases
    if(n==0)
        return 0;
    
    if(sum==0)
        return 1;

    //choice diagram case
    if(t[n-1][sum]!=-1)
    {
        return t[n-1][sum];
    }
    if(arr[n-1]>sum)
    {
        return t[n-1][sum] = isSubsetSum(arr, n-1, sum);
    }
    else
        return t[n-1][sum] = isSubsetSum(arr, n-1, sum-arr[n-1]) || isSubsetSum(arr, n-1, sum);
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 6;
    int n = sizeof(arr)/sizeof(arr[0]);
    initialize();
    if(isSubsetSum(arr, n, sum)==true)
        cout<<"Subset found"<<endl;
    else
        cout<<"Subset not found"<<endl;
    return 0;
}