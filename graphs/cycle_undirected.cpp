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
bool iscycle(int curr_node, vector<vector<int>> adj, vector<bool> &visited, int parent)
{

    visited[curr_node] = true;
    for (auto i : adj[curr_node])
    {
        if (i != parent)
        {
            if (visited[i])
                return true;
            if (!visited[i] && iscycle(i, adj, visited, curr_node))
                return true;
        }
    }
    return false;
}
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n, false);
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // dfs(1, adj, visited);
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && iscycle(i, adj, visited, -1))
        {
            flag = true;
            break;
        }
    }
    if (flag)
        cout << "Cycle is present\n ";
    else
        cout << "Cycle is not present\n";
    return 0;
}