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
//find the sum of a subarray whose sum<x but it is maximum
//****************************************************************************
int main()
{
    ll n,k,maxsum;
    cin >> n>>k>>maxsum;
    vi v;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int sum=0;
    int ans=INT_MIN;
    rep(i,0,k)
    {
        sum+=v[i];
    }
    if(sum<maxsum)
    {
        ans=max(sum,ans);
    }
    rep(i,k,n)
    {
        sum+=v[i];
        sum-=v[i-k];
        if(sum<maxsum)
            ans=max(sum,ans);
    }
    cout<<ans;
    return 0;
}