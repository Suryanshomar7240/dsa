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
const int N = 1e5 + 2,MOD=1e9+7;
vector<ll> dp(N, -1);
ll fib(int n)
{
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = (fib(n - 1)%MOD + fib(n - 2)%MOD)%MOD;
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
        cout << fib(n) << endl;
    }
    return 0;
}