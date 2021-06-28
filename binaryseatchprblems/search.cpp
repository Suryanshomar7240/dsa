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
//search a element in a sorted but roated array about a pivot point
// ex:- [30,40,50,10,20]
//****************************************************************************
bool searching(int ele, vi v, int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (v[mid] == ele)
            return true;
        if (ele > v[ele])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}
bool search(vi v, int ele)
{
    int start = 0, end = v.size();
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (v[mid] > v[mid + 1])
        {
            break;
        }
        if (v[mid] > v[start])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
}
int main()
{
    ll n, x;
    cin >> n;
    vi c;
    rep(i, 0, n)
    {
        cin >> x;
        c.push_back(x);
    }
    int ele;
    cin >> ele;
    cout << search(c, ele);
    return 0;
}