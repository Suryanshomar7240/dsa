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
//bitonic means first increasing then decresing subsequence
//it may be fully incresing or fully decresing
const int N=1e5+7;
int forwards[N];//reprsent longest incresing subsequence upto i
int backward[N];//repesent longest decresing subsequence from i to n-1
// int dp[N][N];
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    for(int i=0;i<N;i++)
    {
        forwards[i]=1;
        backward[i]=1;
    }
    int n;
    cin>>n;
    int arr[n];
    rep(i,0,n)
        cin>>arr[i];
    for(int i=0;i<n;i++)
    {
        if(i)
            forwards[i]=forwards[i-1];
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
                forwards[i]=max(forwards[i],1+forwards[j]);
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(i!=n-1)
            backward[i]=backward[i+1];
        for(int j=n-1;j>i;j--)
        {
            if(arr[i]>arr[j])
                backward[i]=max(backward[i],1+backward[j]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,forwards[i]+backward[i]-1);
    }
    cout<<ans;
    return 0;
}