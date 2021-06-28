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
//find the minimum subarray size of sum>x
//****************************************************************************
int main()
{
    ll n, k, maxsum;
    cin >> n >> maxsum;
    vi v;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int sum = 0;
    int ans = INT_MAX;
    int start = 0;
    rep(i, 0, n)
    {
        sum += v[i];
        if (sum > maxsum)
        {
            ans = min(ans, i - start);
            while (sum > maxsum && i >= start)
            {
                if (sum - v[start] >= maxsum)
                {
                    start++;
                    ans = min(ans, i - start);
                    sum -= v[start + 1];
                }
                else
                    break;
            }
        }
    }
    cout << ans;
    return 0;
}