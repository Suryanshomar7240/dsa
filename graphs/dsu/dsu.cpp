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
//                      MAIN
//*******************************************************
class dsu
{
    public:
    int *parent;
    dsu(int n)
    {
        parent=new int[n];
        rep(i,0,n)
            parent[i]=i;
    }
    int find_parent(int a)
    {
        if(a==parent[a])
            return a;
        return find_parent(parent[a]);
    }
    void uni(int a,int b)
    {
        if(parent[a]==parent[b])
            return;
        parent[b]=parent[a];
    }
};
int main()
{
    dsu se(10);
    se.uni(1,2);
    se.uni(3,4);
    se.uni(2,3);
    cout<<se.find_parent(1)<<endl;
    cout<<se.find_parent(2)<<endl;
    cout<<se.find_parent(3)<<endl;
    cout<<se.find_parent(4)<<endl;
    return 0;
}