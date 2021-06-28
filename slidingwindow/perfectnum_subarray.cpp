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
//find maximum no of perfert number that can exist in a subarray of size k
//Perfect Number : number which is equal to the sum of its divisors
//****************************************************************************
bool isPerfect(int n)
{
    int sum = 1;
    
    rep(i, 2, sqrt(n))
    {
        if (n % i == 0)
        {
            if (i == n / i)
                sum += i;
            else
                sum += (n / i) + i;
        }
    }
    return sum == n && n != 1;
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
    rep(i, 0, n)
    {
        if (isPerfect(v[i]))
        {
            v[i] = 1;
        }
        else
        {
            v[i] = 0;
        }
    }
    int sum = 0;
    int ans = INT_MIN;
    rep(i, 0, k)
    {
        sum += v[i];
    }
    ans = max(sum, ans);
    rep(i, k, n)
    {
        sum = sum + v[i] - v[i - k];
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}