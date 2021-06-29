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
//                    Question
// finding cost for traverseing from source node
//algo fails when negative edege occur
//*******************************************************

//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    const int inf = 1e9;
    vector<int> dis(n, inf);
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int source;
    cin >> source;
    dis[source] = 0;
    set<pair<int, int>> s;
    // {wt, node}
    s.insert({0, source});
    int cost = 0;
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        int u = x.second;
        int w = x.first;
        for (auto i : adj[u])
        {
            if (dis[i.first] > dis[u] + i.second)
            {
                s.erase(make_pair(dis[i.first], i.first));
                dis[i.first] = i.second+dis[u];
                s.insert(make_pair(dis[i.first], i.first));
            }
        }
    }
    for(auto i:dis)
    {
        if(i<inf)
            cout<<i<<" ";
        else
            cout<<"-1 ";   
    }
    return 0;
}