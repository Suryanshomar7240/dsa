#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int dp[N][N];
int lcs(vector<int> &s1, vector<int> &s2, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != 0)
        return dp[n][m];
    if (s1[n - 1] == s2[m - 1])
        dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1);
    else
    {
        dp[n][m] = max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
    }
    return dp[n][m];
}
int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            dp[i][j] = 0;
    }
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    cout << lcs(a, b, n, m);
    return 0;
}