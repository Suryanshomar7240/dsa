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
//
//****************************************************************************
int powerof10(int n)
{
    int ans = 0;
    while (n > 0)
    {
        n = n / 10;
        ans++;
    }
    return ans;
}
int main()
{
    ll n, k, maxsum;
    cin >> n >> k;
    vi v;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int number = v[0];
    rep(i, 1, k)
    {
        number = number * pow(10, powerof10(v[i])) + v[i];
    }
    if (number % 3 == 0)
    {
        rep(j, 0, k)
        {
            cout << v[j] << " ";
        }
    }
    rep(i, k, n)
    {
        int modulo = pow(10, powerof10(number) - powerof10(v[i - k]))+1;
        number = number % modulo;
        number = (number * pow(10, powerof10(v[i]))) + v[i];
        if (number % 3 == 0)
        {
            rep(j, i - k + 1, i + 1)
            {
                cout << v[j] << " ";
            }
        }
    }
    return 0;
}