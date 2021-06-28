#include<bits/stdc++.h>
using namespace std;
vector<int>
int left(int i)
{
    return 2*i+1;
}
int right(int i)
{
    return 2*i+2;
}
int parent(int i)
{
    return (i-1)/2;
}
void insert(vector<int> &v,int &n,int key)
{
    n+=1;
    v.push_back(key);
    int currentindex=n;
    while(currentindex>0)
    {
        if(v[parent(currentindex)]<v[currentindex])
        {
            int pare=parent(currentindex);
            int temp=v[currentindex];
            v[currentindex]=v[pare];
            v[pare]=temp;
        }
        else{
            return;
        }
    }
}
int main()
{
    vector<int> v;
    int currentsize=-1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        insert(v,currentsize,a);
    }
    for(auto x:v)
    {
        cout<<x<<" ";
        
    }
    return 0;
}