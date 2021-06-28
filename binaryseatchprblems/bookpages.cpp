#include <bits/stdc++.h>
typedef long long ll;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b; i >= a; i--)
#define error(x) cout << x << " ";
//***************************************************************************
//                  Question
//u have given n books which have different no of pages and m students
//u have to distrbute those books to students such that maximum no of pages obtained by a kid is minimum
//****************************************************************************
using namespace std;
bool isfeasible(vi v, int mid, int m)
{
    int studentRequiredd = 1, sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > mid)
        {
            return false;
        }
        if (sum + v[i] > mid)
        {
            studentRequiredd++;
            sum =v[i];
            if (studentRequiredd > m)
            {
                return false;
            }
        }
        else
        {
            sum += v[i];
        }
    }
    return true;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    vi v;
    int sum = 0;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        v.push_back(x);
        sum += x;
    }
    int start = 0, end = sum, ans = INT_MAX;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (isfeasible(v, mid, m))
        {
            ans = min(mid, ans);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout<<ans<<" ";
    return 0;
}