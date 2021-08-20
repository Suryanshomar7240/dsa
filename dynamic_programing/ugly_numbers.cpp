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
// ugly numbers are those whose primes factors are only 2,3,5
// we have to find the Nth ugly number in this quetion
// const int N = 1e5 + 7;
// int dp[N];
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    int n;
    cin >> n;
    int c2 = 0, c3 = 0, c5 = 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = min((2 * dp[c2]), min((dp[c3] * 3), (dp[c5] * 5)));
        if (dp[i] == (dp[c2] * 2))
            c2++;
        if (dp[i] == (dp[c3] * 3))
            c3++;
        if (dp[i] == (dp[c5] * 5))
            c5++;
    }
    cout << dp[n - 1];
    return 0;
}