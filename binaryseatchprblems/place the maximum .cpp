#include<bits/stdc++.h>
using namespace std;
//***************************************************************************
//                  Question
//given an array of no of elements=n 
//ans a value k given
//We have to find out a maximum value for which an sbarray of k elements 
//in which each element have atleast that differece( max number)
//****************************************************************************
bool isfeasbile(int mark,vector<int> v,int k)
{
    int pos=v[0];
    int element=1;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]-pos>=mark)
        {
            pos=v[i];
            element++;
            if(element>=k)
                return true;
        }
    }
    return false;
}
int main()
{
    int n,ele,k;
    vector<int> v;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        v.push_back(ele);
    }
    sort(v.begin(),v.end());
    int left=1;
    int right=v[v.size()-1];
    int mid;
    int maxi=0;
    while(right>left)
    {
        mid=(left+right)/2;
        if(isfeasbile(mid,v,k))
        { 
            maxi=max(maxi,mid);
            left=mid+1;
        }
        else
        {
            right=mid;
        }
    }
    cout<<maxi<<" ";
    return 0;
}