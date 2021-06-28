#include <bits/stdc++.h>
typedef long long ll;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = b; i >= a; i--)
#define error(x) cout << x << " ";
using namespace std;

//*******************************************************
// Type your code here for each test case
//*******************************************************

//*******************************************************
//                      MAIN
//*******************************************************
const unsigned int N = 1e5 + 2;
vi adj[N];
vi visited(N + 1, 0);
int main()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> que;
    que.push(1);
    visited[1] = 1;
    while (!que.empty())
    {
        int temp = que.front();
        que.pop();
        for (int i : adj[temp])
        {
            if (visited[i] == 0)
            {
                que.push(i);
                visited[i] = 1;
            }
        }
        cout << temp << " ";
    }
    return 0;
}