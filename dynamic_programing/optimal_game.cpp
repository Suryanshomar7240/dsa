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
//  there are two player u and your oppenent both have same iq level
//  there are a N- group of coins present and u have to choose one group
// of coins turn by turn to acheive the maximum no of as u get 
// NOTE: u can only choose a group their from first or last

const int N = 1e3 + 2, MOD = 1e9 + 7;
int arr[N];
int dp[N][N];//represent final score if i,j are intial and final index
int solve(int i,int j)//i j represent first and final state
{
    if(i==j)
        return arr[i];
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int l=arr[i]+min(solve(i+2,j),solve(i+1,j-1));//if he selected i
    int r=arr[j]+min(solve(i+1,j-1),solve(i,j-2));//if he selected r
    //here minimum of next state is used because your oppenent want to decrease 
    // your coins as much as he can
    return dp[i][j]=max(l,r);//maximum of both cases will be the answer
}
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    rep(i, 0, N)
    {
        rep(j,0,N)
            dp[i][j] = -1;
    }
    int n;
    cin>>n;
    rep(i,0,n)
        cin>>arr[i];
    cout<<solve(0,n-1);
    return 0;
}