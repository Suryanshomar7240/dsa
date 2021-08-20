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
int v[N], W[N];
int dp[N][N];
int Knapspack(int n, int w)
{
    if (w <= 0 || n <= 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (W[n - 1] > w)
        dp[n][w] = Knapspack(n - 1, w);
    else
        dp[n][w] = max(Knapspack(n - 1, w), Knapspack(n - 1, w - W[n - 1]) + v[n - 1]);
    return dp[n][w];
}
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    rep(i, 0, N)
    {
        rep(j, 0, N)
            dp[i][j] = -1;
    }
    int n;
    cin >> n;
    rep(i, 0, n)
            cin >>
        W[i];
    rep(i, 0, n)
            cin >>
        v[i];
    int w;
    cin >> w;
    cout << Knapspack(n, w) << endl;
    return 0;
}