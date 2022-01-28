// C++ program to check whether a sudoku board is valid or not
#include<bits/stdc++.h>
using namespace std;

// function to check whether a particular number is present in the specified row or not
bool checkRow(int arr[][9], int row)
{
    set <int> st;
    for(int i=0; i<9; i++)
    {
        if(st.find(arr[row][i]) != st.end()) //if already present int the row, then return false
            return false;

        if(arr[row][i] != 0) //if not present in the set and the value is not 0, then add it to the set
            st.insert(arr[row][i]);
    }
    return true;
}

// function to check whether a particular number is present in the specified column or not
bool checkCol(int arr[][9], int col)
{
    set <int> st;
    for(int i=0; i<9; i++)
    {
        if(st.find(arr[i][col]) != st.end()) //if already present in the column, then return false
            return false;
        
        if(arr[i][col] != 0) //if not present in the set and value is not 0, then add it to the set
            st.insert(arr[i][col]);
    }
    return true;
}

// function to check whether there is any duplicate in current 3X3 box or not
bool checkBox(int arr[][9], int row, int col)
{
    set <int> st;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            int curr = arr[i + row][j + col];
            if(st.find(curr) != st.end()) //if present in the 3X3 box, then return false
                return false;

            if(curr != 0)
                st.insert(curr);
        }
    }
    return true;
}

bool isValid(int arr[][9], int row, int col)
{
    return checkRow(arr, row) && checkCol(arr, col) && checkBox(arr, row - row%3, col - col%3);
}

bool isValidConfig(int arr[][9], int n)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(!isValid(arr, i, j))
                return false;
        }
    }
    return true;
}

int main()
{
    int board[9][9] = {{5,3,0,0,7,0,0,0,0},
                       {6,0,0,1,9,5,0,0,0},
                       {0,9,8,0,0,0,0,6,0},
                       {8,0,0,0,6,0,0,0,3},
                       {4,0,0,8,0,3,0,0,1},
                       {7,0,0,0,2,0,0,0,6},
                       {0,6,0,0,0,0,2,8,0},
                       {0,0,0,4,1,9,0,0,5},
                       {0,0,0,0,8,0,0,7,9}};
    
    cout<<(isValidConfig(board, 9) ? "Yes\n" : "No\n");
    return 0;
}