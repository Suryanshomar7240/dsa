#include <iostream>
using namespace std;
bool isafe(int** arr, int x, int y, int n)
{
     int row, col;
    for (int i = 0; i < x; i++)
    {
       
        if (arr[i][y] == 1)
        {
            return false;
        }
    }
    row = x;
    col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    row = x;
    col = 0;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}
bool nqueen(int** arr, int x, int y, int n)
{
    if (x >= n)
    {
        return true;
    }
    if(isafe(arr,x,y,n))
    {
        arr[x][y]= 1;
        return true;
    }
    if(nqueen(arr,x+1,y,n))
    {
        return true;
    }
    arr[x][y]=0;
    return false;
}
int main()
{
    int n;
    cin >> n;
    int** arr=new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j]= 0;
        }
    }
    if(nqueen(arr,0,0,n))
    {
        for (int  i = 0; i <n; i++)
        {
            for(int j=0;j<n;j++)
                 cout<<arr[i][j]<<" ";
            cout<<endl;
        }
        
    }
    return 0;
}