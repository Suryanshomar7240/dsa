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
/* Given an array A1,A2…AN, find the minimum number of operations
(possibly zero) required to convert all integers in A to 0. In one operation, you
choose a non-negative integer p (p≥0),select at most K indices in the array A, and
for each selected index i, replace Ai with Ai⊕2p. Here, ⊕ denotes bitwise XOR. */
// //***********************************************************************************
void modify(vector<int> &temp, vector<ll> &v, ll idx, ll &ans)
{
    // cout<<v[idx]<<" ";
    while (v[idx] != 0)
    {
        double X = log2(v[idx]);
        ll N = X;
        double temp2 = N - X;
        if (temp2 > 0)
        {
            temp[N]++;
            v[idx] = 0;
            break;
        }
        else
        {
            ll diff = v[idx] - pow(2, N);
            v[idx] = diff;
            temp[N]++;
        }
    }
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
        ll n, k;
        cin >> n >> k;
        vector<ll> v;
        ll maximum = INT_MIN;
        ll x;
        for (ll i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
            maximum = max(maximum, x);
        }
        if (maximum > 0)
        {
            ll maxpow = log2((ll)maximum);
            vector<int> temp(maxpow + 1, 0);
            ll ans = 0;
            for (ll i = 0; i < n; i++)
            {
                if (v[i] % 2 != 0)
                {
                    temp[0]++;
                    v[i]--;
                }
                modify(temp, v, i, ans);
            }
            for (int i = 0; i < temp.size(); i++)
            {
                ans += (ceil(temp[i] / (float)k));
            }
            cout << ans << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}