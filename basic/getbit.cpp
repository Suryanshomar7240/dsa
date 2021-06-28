#include<iostream>
using namespace std;
bool getbit(int a,int i)
{
    return (a&(1<<i)!=0);
}
int setbit(int n,int i)
{
    return (n|(1<<i));
}
int clearbit(int n,int i)
{
    int x=~(1<<i);
    return (n&(x));
}
int updatebit(int n,int i,int value)
{
    n=(n&(~(1<<i)));
    return (n|(value<<i));
}
int main()
{
    cout<<getbit(5,2)<<endl;
    cout<<setbit(5,1)<<endl;
    cout<<clearbit(7,1)<<endl;
    cout<<updatebit(5,0,1);
    return 0;
}