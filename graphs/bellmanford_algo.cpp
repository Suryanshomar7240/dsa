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
//Negative cycle can be detected 
//we can also take negative edeges
//*******************************************************

//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<vector<int>> edges;
    const int inf = 1e9;
    vector<int> dis(n, inf);
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >>
        
         v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u,v,w});
   }
    int source;
    cin >> source;
    dis[source] = 0;
    for(int i=0;i<n-1;i++)
    {
        //for negative cycle detection
        //bool cycle=false;

        for(auto j:edges)
        {
            int u=j[0];
            int v=j[1];
            int w=j[2];

            //for negative cycle detection
            // if(dis[v]>dis[u]+w)
            //     cycle=true;
            //it means that if the chances happens in n-1 trial that means it there is  - ve cycle present

            dis[v]=min(dis[v],w+dis[u]);
        }
    }
    
    //for negative cycle detection
    // if(cycle)
    //     cout<<"negative cycle is present";

    for(auto i:dis)
    {
        if(i<inf)
            cout<<i<<" ";
        else
            cout<<"-1 ";   
    }
    return 0;
}