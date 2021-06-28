#include<iostream>
using namespace std;
int det(int **arr,int n)
{
    if(n==2)
    {
        return ((arr[0][0]*arr[1][1])-(arr[1][0]*arr[0][1]));
    }
    int sum=0,sign=1;
    for(int k=0;k<n;k++)
    {
        int** A=new int*[n-1];
        for(int a=0;a<n-1;a++)
        {
            A[a]=new int[n-1];
            for(int b=0;b<n;b++)
            {
                if(b!=k)
                {
                    if(b>k)
                    {
                        A[a][b-1]=arr[a+1][b];
                    }
                    else
                    {
                        A[a][b]=arr[a+1][b];
                    }
                    
                }
            }
        }
        sum=sum+(arr[0][k]*det(A,n-1)*sign);
        sign*=-1;
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    int** arr =new int*[n];
    for (int i = 0; i <n; i++)
    {
        arr[i]=new int[n];
        for (int j = 0; j <n; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<endl<<det(arr,n);
    return 0;    
}