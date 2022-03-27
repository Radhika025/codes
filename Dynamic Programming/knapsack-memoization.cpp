#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int t[5][11];
//memset(t, -1, sizeof(t));

//t[n][w], where n = n+1 and w = w+1. As n=4 and w=10, therefore t[5][11]
void initialize()
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<11; j++)
            t[i][j] = -1;
    }
}

int knapsack(int wt[], int val[], int w, int n)
{
    if(t[n][w]!=-1) //base case = smallest valid input
        return t[n][w];
    
    //dervied from choice diagram

    //             w1
    //            /  \
    //     w1<=w      w1>w
    //     /  \            \
    // yes     no           no
    if(wt[n-1]<=w)
        {
            t[n][w] =  max(val[n-1] + knapsack(wt, val, w-wt[n-1], n-1), knapsack(wt, val, w, n-1));
            return t[n][w];
        }
    
    else
       {
           t[n][w] = knapsack(wt, val, w, n-1);
           return t[n][w];
       } 

    //return t[n][w];
}

int main()
{
    int wt[] = {1, 3, 4, 5}; //weight of items
    int val[] = {1, 4, 5, 7}; //value of items 
    int w = 10; //capacity of the bag
    int n = sizeof(wt)/sizeof(wt[0]);
    initialize();
    cout<<knapsack(wt, val, w, n);
    return 0;
}