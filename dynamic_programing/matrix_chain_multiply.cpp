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
const int N = 1e3 + 2, MOD = 1e9 + 7;
int arr[N];
int dp[N][N];
int mcm(int i,int n)
{
    if(i==n)
        return 0;
    if(dp[i][n]!=-1)
        return dp[i][n];
    dp[i][n]=MOD;
    for(int k=i;k<n;k++)
    {
        dp[i][n]=min(dp[i][n],mcm(i,k)+mcm(k+1,n)+(arr[i-1]*arr[k]*arr[n]));
    }
    return dp[i][n];
}
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    rep(i,0,N)
    {
        rep(j,0,N)
            dp[i][j]=-1;
    }
    int n;
    cin>>n;
    rep(i,0,n)
        cin>>arr[i];
    cout<<mcm(1,n-1);
    return 0;
}