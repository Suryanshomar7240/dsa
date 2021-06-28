#include <bits/stdc++.h>
using namespace std;
class Matrix
{
public:
    int row;
    int col;
    int **arr;
    Matrix(int i=3, int j=3)
    {
        row = i;
        col = j;
        arr=new int*[row];
        for(int i=0;i<row;i++)
        {
            arr[i]=new int[col];
            for(int j=0;j<col;j++)
            {
                arr[i][j]=0;
            }
        }
    }
    void getdata()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
    void putdata()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout<<endl;
    }
    // Matrix operator = (Matrix &m1)
    // {
    //     row=m1.row;
    //     col=m1.col;
    //     for (int i=0;i<row;i++)
    //     {
    //         for(int j=0;j<col;j++)
    //         {
    //             arr[i][j]=m1.arr[i][j];
    //         }
    //     }
    // }
};
int main()
{
    Matrix m1(3,3);
    m1.getdata();
    m1.putdata();
    Matrix m2=m1;
    m2.putdata();
    Matrix m3;
    m3.putdata();
    return 0;
}