#include <stdio.h>
/*This is the program in which it takes a 9*9 input sudoku matrix in which user must have to enter 0 in blank spaces
 this programed by different students of 1st year of IIIT kalyani
 here are our contributers
            NAME                           Registration number
            Suryansh omar                       613
            Abhishree                           521
            Ankit Mishra                        538
            Anmol Srivastva                     539
            Anuj kirodia                        540
            Subham Maji                         610
            Rishab Shukla                       592
            Dev Gupta                           558
            Harsh Vishwakarma                   564
            Khusal Sharma                       570 
*/
/*
**************************************************************************************************
                                        check Functions
**************************************************************************************************
**************************************************************************************************
                                Checking whether the element 
                              we want to add is already exists 
                                     in that row or not
**************************************************************************************************
*/
int rowcheck(int A[9][9], int i, int j, int key) 
{
    int x;
    for (x = 0; x < 9; x++)
    {
        if (key == A[i][x])
        {
            return 0;
        }
    }
    return 1;
}
/*
**************************************************************************************************
                                Checking whether the element 
                              we want to add is already exists 
                                     in that column or not
**************************************************************************************************
*/
int colcheck(int A[9][9], int i, int j, int key)
{
    int x;
    for (x = 0; x < 9; x++)
    {
        if (A[x][j] == key)
        {
            return 0;
        }
    }
    return 1;
}
/*
**************************************************************************************************
                                Checking whether the element 
                              we want to add is already exists 
                                     in that box or sub matrix (3*3) or not
**************************************************************************************************
*/
int boxcheck(int A[9][9], int i, int j, int key) 
{
    int boxrow = i / 3, boxcol = j / 3; //For finding in which box our element is belonging;
    int x,y;
    boxrow=boxrow*3;    //for multipling it by 3 we reched to the
    boxcol=boxcol*3;    //top left postion of that sub matrix (3*3)
    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            if (A[x + boxrow][y + boxcol] == key)
            {
                return 0;
            }
        }
    }
    return 1;
}
/*
**************************************************************************************************
                                Function for combining 
                                all the three sub fuction
**************************************************************************************************
*/
int check(int A[9][9], int i, int j, int key) //Chechking whether the element we want to put is valid according to conditions or not
{
    if (rowcheck(A, i, j, key) == 1 && colcheck(A, i, j, key) == 1 && boxcheck(A, i, j, key) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*
**************************************************************************************************
                                Recursive Function for visting  
                                all the element of that sudoku
                                and putting there correct value 
                                    in there blank spaces
**************************************************************************************************
*/
int solve(int A[9][9], int i, int j)
{
    if (i >= 8 && j >= 8) //base condition
    {
        return 1;
    }
    if (j > 8) //As we are going left to right so if we reach at the end of the column then we change it next row and column =0;
    {
        i++;
        j = 0;
    }
    int c,key;
    if (A[i][j] != 0) //if element is non zero then we just need to continue that;
    {
        c=solve(A, i, j + 1);
        return c; //recursive call
    }
    for (key = 1; key <= 9; key++) //checking whether the elements
    {
        if (check(A, i, j, key) == 1)
        {
            A[i][j] = key;
            if (solve(A, i, j + 1) == 1) //recursive call
            {
                return 1;
            }
        }
        A[i][j] = 0; //backtracking means if the assumstion of us is wrong then we have to reevalute that
    }
    return 0; //if our fun reaches towards the last element and it doesn't return 1 that mean that there is no solution exist so we are giving a message to main that no solution exist;
}
/*
**************************************************************************************************
                                Main Function
**************************************************************************************************
*/
int main()
{
    int A[9][9],i,j;
    printf("Enter the elements of sudoku(Enter 0 if you want it to be a blank) \n");
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");
    /*Checking whether the solution exists or not*/
    if (solve(A, 0, 0) == 1)
    {
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 9; j++)
            {
                if (j == 3 || j == 6)
                {
                    printf("| ");
                }
                printf("%d ", A[i][j]);
            }
            if (i == 2 || i == 5)
            {
                printf("\n----------------------");
            }
            printf("\n");
        }
    }
    else
    {
        printf("No Solution exists:");
    }
    return 0;
}