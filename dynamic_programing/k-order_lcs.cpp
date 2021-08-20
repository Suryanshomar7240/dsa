#include <bits/stdc++.h>
typedef long long ll;
#define vi vector<ll>
#define pi pair<ll, ll>
#define vpi vector<pair<ll, ll>>
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = b; i >= a; i--)
#define error(x) cout << x << " ";
using namespace std;

// //***********************************************************************************
//                        Question
// //***********************************************************************************
// he have to find the lcs
// we can also  change atmost k elements
const int N=300;
int dp[N][N][N];
int lcs(vector<int> &s1,vector<int> &s2,int i,int j,int k)
{
    if(i==0||j==0)
        return 0;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    if(s1[i-1]==s2[j-1])
        return dp[i][j][k]=1+lcs(s1,s2,i-1,j-1,k);
    int c1=0;
    if(k>0)
    {
        c1=1+lcs(s1,s2,i-1,j-1,k-1);
    }
    int c2=max(lcs(s1,s2,i,j-1,k),lcs(s1,s2,i,j-1,k));
    return dp[i][j][k]=max(c1,c2);
}
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    memset(dp,-1,sizeof(dp));
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n,0),b(m,0);
    rep(i,0,n)
        cin>>a[i];
    rep(i,0,m)
        cin>>b[i];
    cout<<lcs(a,b,n,m,k);
    return 0;
}