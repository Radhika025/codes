#include<iostream>
using namespace std;

int knapsack(int wt[], int val[], int w, int n)
{
    if(n==0 || w==0) //base case = smallest valid input
        return 0;
    
    //dervied from choice diagram

    //             w1
    //            /  \
    //     w1<=w      w1>w
    //     /  \            \
    // yes     no           no
    if(wt[n-1]<=w)
        return max(val[n-1] + knapsack(wt, val, w-wt[n-1], n-1), knapsack(wt, val, w, n-1));
    
    else
        return knapsack(wt, val, w, n-1);
}

int main()
{
    int wt[] = {1, 3, 4, 5}; //weight of items
    int val[] = {1, 4, 5, 7}; //value of items 
    int w = 10; //capacity of the bag
    int n = sizeof(wt)/sizeof(wt[0]);
    cout<<knapsack(wt, val, w, n);
    return 0;
}