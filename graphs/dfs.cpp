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
void dfs(int curr_node, vector<vector<int>> adj, vector<bool> &visited)
{
    
    visited[curr_node] = true;
    //preoder
    
    //palce cout line here if u want preorder

    //inoder
    for (auto i : adj[curr_node])
    {
        if (!visited[i])
            dfs(i, adj, visited);
    }
    
    //postoder
    cout << curr_node << " ";
}
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, adj, visited);
    return 0;
}