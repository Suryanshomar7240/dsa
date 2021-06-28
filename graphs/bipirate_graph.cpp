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
bool isbi(vector<vector<int>> adj)
{
    vector<int> visited(adj.size(),0);
    queue<int> pq;
    pq.push(0);
    visited[0]=1;
    while(!pq.empty())
    {
        int curr=pq.front();
        pq.pop();
        int curr_color=(visited[curr]==1)?2:1;
        for(auto i:adj[curr])
        {
            if(!visited[i])
                visited[i]=curr_color;
            else if(visited[i]!=curr_color)
                return false;
        }
    }
    return true;
}
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    return 0;
}