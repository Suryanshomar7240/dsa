#include <bits/stdc++.h>
typedef long long ll;
#define vi vector<ll>
#define pi pair<ll, ll>
#define vpi vector<pair<ll, ll>>
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = b; i >= a; i--)
#define error(x) cout << x << " ";
using namespace std;

// //***********************************************************************************
//                        Question
// //***********************************************************************************
// this is same as 01knapsack 
// but in this question we can take same item as many times as possible 
const int N=1e3+7;
int W[N],v[N];
int dp[N][N];
int knapsack(int i,int w)
{
    if(i<0)
        return 0;
    if(dp[i][w]!=-1)
        return dp[i][w];
    if(W[i]>w)
        dp[i][w]=knapsack(i-1,w);
    else
        dp[i][w]=max(knapsack(i-1,w),v[i]+knapsack(i,w-W[i]));
    return dp[i][w];
}
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            dp[i][j]=-1;

    }
    int n;
    cin>>n;
    rep(i,0,n)
        cin>>W[i];
    rep(i,0,n)
        cin>>v[i];
    int w;
    cin>>w;
    cout<<knapsack(n-1,w);
    return 0;
}