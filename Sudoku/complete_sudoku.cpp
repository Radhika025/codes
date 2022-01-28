//code to complete the sudoku and print the final output
#include<bits/stdc++.h>
using namespace std;

#define n 9

void print(int arr[n][n])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

//checks if it is correct to assign num to the given row and column index
bool check(int arr[n][n], int row, int col, int num)
{
    //checks for the same number in the similar row
    for(int x=0; x<8; x++)
    {
        if(arr[row][x] == num)
            return false;
    }

    //checks for the same number in the similar column
    for(int x=0; x<8; x++)
    {
        if(arr[x][col] == num)
            return false;
    }

    //checks for the same number in the same 3X3 box matrix
    int startrow = row - row%3;
    int startcol = col - col%3;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(arr[i + startrow][j + startcol] == num)
                return false;
        }
    }

    return true;
}

//function to fill the indexes in sudoku with have are assigned 0 value
bool solve(int arr[n][n], int row, int col)
{
    // (base case) checks for the 8th row index and 9th column index to avoid further backtracking
    if(row == n-1 && col == n)
        return true;

    //updates the column index value to 0 and increments the row index value when it reaches the last column for a particular row index
    if(col == n)
    {
        row++;
        col = 0;
    }

    if(arr[row][col]>0)
        return solve(arr, row, col+1);

    for(int num=1; num<=n; num++)
    {
        // checks for every number in range 1-9 if it is safe to assign it to arr[row][col]
        if(check(arr, row, col, num))
        {
            arr[row][col] = num;

            //checks for the next possibility with next column
            if(solve(arr, row, col+1))
                return true;
        }
        //removes the assigned value if the assumption returns false
        arr[row][col] = 0;
    }
    return false;
}

int main()
{
    int arr[n][n] = { { 0, 0, 6, 0, 0, 8, 4, 0, 0 },
                      { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                      { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                      { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                      { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                      { 0, 5, 0, 0, 0, 0, 6, 0, 0 },
                      { 1, 3, 0, 0, 0, 0, 0, 0, 0 },
                      { 0, 0, 0, 0, 0, 0, 0, 7, 0 },
                      { 0, 0, 5, 2, 0, 6, 3, 0, 0 }};
    if(solve(arr, 0, 0))
        print(arr);
    else
        cout<<"No solution exists"<<endl;
    return 0;
}