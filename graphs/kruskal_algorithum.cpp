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
    int u, v,w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    int cost=0;
    dsu se(n);
    for(auto i:edges)
    {
        w=i[0];
        u=i[1];
        v=i[2];
        int x=se.find_parent(u);
        int y=se.find_parent(v);
        if(x==y)
            continue;
        else
        {
            cout<<u<<" "<<v<<"\n";
            cost+=w;
            se.uni(u,v);
        }
    }
    cout<<"Total cost="<<cost;
    return 0;
}