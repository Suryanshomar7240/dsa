#include <bits/stdc++.h>
using namespace std;
const int N = 300;
int dp[N][N][N];
int lcs(string &s1, string &s2, string &s3, int n, int m, int o)
{
    if (n == 0 || m == 0 || o == 0)
        return 0;
    if (dp[n - 1][m - 1][o - 1] != -1)
        return dp[n - 1][m - 1][o - 1];
    if (s1[n - 1] == s2[m - 1] && s1[n - 1] == s3[o - 1])
        return dp[n - 1][m - 1][o - 1] = 1 + lcs(s1, s2, s3, n - 1, m - 1, o - 1);
    else
    {
        int l = lcs(s1, s2, s3, n, m, o - 1);
        int r = lcs(s1, s2, s3, n - 1, m, o);
        int p = lcs(s1, s2, s3, n, m - 1, o);
        return dp[n - 1][m - 1][o - 1] = max({l, r, p});
    }
}
int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
                dp[i][j][k] = -1;
        }
    }
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << lcs(s1, s2, s3, s1.length(), s2.length(), s3.length());
    return 0;
}