#include<iostream>
using namespace std;
void toh(int n,char A,char C,char B)
{
    if(n==0)
    {
        return;
    }
    toh(n-1,A,B,C);
    cout<<"Move 1 block from "<<A<<" to "<<C<<endl;
    toh(n-1,B,A,C);
}
int main()
{
    int n;
    cin>>n;
     toh(n,'A','B','C');
    return 0;
}