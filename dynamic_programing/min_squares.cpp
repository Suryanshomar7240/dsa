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
vector<ll> dp(N, MOD);
ll minsqu(int n)
{
    if (n == 0 || n == 1 || n == 2 || n == 3)
        return n;
    if (dp[n] != MOD)
        return dp[n];
    for (int i = 1; i * i <= n; i++)
    {
        dp[n]=min(dp[n],minsqu(n-(i*i))+1);
    }
    return dp[n];
}
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        //bottom-up method
        //vi dp(n+1)
        // dp[0]=0;
        // dp[1]=1;
        // dp[2]=1;
        // for(int i=3;i<=n;i++)
        //     dp[i]=dp[i-1]+dp[i-2];

        //up-bottom table
        cout << minsqu(n) << endl;
    }
    return 0;
}