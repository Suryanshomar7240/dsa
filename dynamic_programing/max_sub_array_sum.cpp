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

//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int currsum=0,maxsum=0;
    for(int i=0;i<n;i++)
    {
        currsum+=arr[i];
        maxsum=max(maxsum,currsum);
        if(currsum<0)
            currsum=0;
    }
    return 0;
}