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
//           Question of Minimum spanning tree
//*******************************************************

//*******************************************************
//                      MAIN
//*******************************************************
class dsu
{
public:
    int *parent;
    int *sze;
    dsu(int n)
    {
        parent = new int[n];
        sze=new int[n];
        rep(i, 0, n)
        {
            parent[i] = i;
            sze[i] = 1;
        }
    }
    int find_parent(int a)
    {
        if (a == parent[a])
            return a;
        return parent[a] = find_parent(parent[a]);
    }
    void uni(int a, int b)
    {
        if (parent[a] == parent[b])
            return;
        if (sze[parent[a]] > sze[parent[b]])
        {
            parent[b] = parent[a];
            sze[parent[a]] += sze[parent[b]];
        }
        else
        {
            parent[a] = parent[b];
            sze[parent[b]] += sze[parent[a]];
        }
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> edges;
    const int inf=1e9;
    vector<int> dis(n,inf);
    vector<bool> visited(n,false);
    int u, v,w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({w,u,v});
    }
    set<pair<int,int>> s;
    s.insert({0,0});
    visited[0]=true;
    int cost=0;
    dsu se(n);
    while(!s.empty())
    {
        auto x=*(s.begin());
        for(auto i:ad
        j[x.second])
        {
            if(!visited[i])
            {
                s.insert()
            }
        }
    }
    cout<<"Total cost="<<cost;
    return 0;
}