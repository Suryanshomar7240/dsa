#include <bits/stdc++.h>
typedef long long ll;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b; i >= a; i--)
#define error(x) cout << x << " ";
using namespace std;
//***************************************************************************
//                  Question
//Find the maxima in the list using binary search
//****************************************************************************
int peakele(vi v)
{
    int n=v.size();
    if(v[0]>v[1])
        return 0;
    int start=0,end=n-1;
    int mid;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(v[mid]>=v[mid+1]&& v[mid]>=v[mid-1])
        {
            return mid;
        }
        else if(v[mid-1]>v[mid])
            end=mid-1;
        else
            start=mid+1;
    }
    if(v[n-1]>=v[n-2]&&n>2)
       return n-1;
    return -1;
}
int main()
{
    ll n;
    cin >> n;
    vi v;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout<<v[peakele(v)];
    return 0;
}