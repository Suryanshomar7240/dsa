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
const int N = 1e5 + 2, MOD = 1e9 + 7;
int arr[N];
int dp[N];//represnts no of moves taken to reach the ith position
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    rep(i, 0, N)
    {
        
        dp[i] = MOD;
    }
    int n;
    cin >> n;
    rep(i, 0, n)
        cin >> arr[i];
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(i<=j+arr[j])
                dp[i]=min(dp[i],dp[j]+1);
        }
    }
    cout<<dp[n-1];
    return 0;
}