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
//           Minimum spanning tree
//*******************************************************

//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1);
    vector<vector<int>> edges;
    const int inf = 1e9;
    vector<int> dis(n+1, inf);
    vector<bool> visited(n+1, false);
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int source=1;
    dis[source] = 0;
    set<pair<int, int>> s;
    vector<int>  parent(n+1,-1);
    // {wt, node}
    s.insert({0, source});
    int cost = 0;
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        visited[x.second] = true;
        int u = x.second;
        int w = x.first;
        if(u!=source)
            cout<<parent[u]<<" "<<u<<" "<<w<<endl;
        cost += w;
        for (auto i : adj[u])
        {
            if (visited[i.first])
                continue;
            else if (dis[i.first] == inf)
            {
                dis[i.first] = i.second;
                s.insert({dis[i.first], i.first});
                parent[i.first]=u;
            }
            else if (dis[i.first] > i.second)
            {
                s.erase(make_pair(dis[i.first], i.first));
                dis[i.first] = i.second;
                s.insert(make_pair(dis[i.first], i.first));
                parent[i.first]=u;
            }
        }
    }
    cout << "Total cost=" << cost;
    return 0;
}