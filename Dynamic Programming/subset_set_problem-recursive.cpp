//Program to return a boolean result if a subset equal to the gievn sum is present in the array

//Recursive approach
#include<iostream>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum)
{
    //base cases
    if(n==0)
        return false;
    
    if(sum==0)
        return true;

    //choice diagram case
    if(arr[n-1]>sum) //if last element is greater than the sum then ignore its
        return isSubsetSum(arr, n-1, sum);
    
    return isSubsetSum(arr, n-1, sum-arr[n-1]) || isSubsetSum(arr, n-1, sum);
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int sum = 11;
    int n = sizeof(arr)/sizeof(arr[0]);
    if(isSubsetSum(arr, n, sum)==true)
        cout<<"Subset found"<<endl;
    else
        cout<<"Subset not found"<<endl;
    return 0;
}