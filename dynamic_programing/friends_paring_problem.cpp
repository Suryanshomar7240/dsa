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
//there are N friends 
// A friend can be single or can be paired
//find no of ways it can be done
const int N=1e5+7;
int dp[N];//ith index repesent the ans if n=i
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    int n;
    cin>>n;
    dp[0]=1;
    stack<int> q;
    q.empty();
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+(i-1)*dp[i-2];
        // dp[i-1] repesent if ith person remains single
        //n-1 represent no of perosn he can pair with 
        //dp[n-2] repesent rest of friends if ith get paired up
    }
    cout<<dp[n];
    return 0;
}