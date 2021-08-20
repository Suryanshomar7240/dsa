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
// A no N is given we have to find the no possible binary string
// of length N which doesn't contain consecutive ones
const int N=1e5+7;
int ones[N];//ith index represents no of binaary strings of length i ending with 1
int zeros[N];//ith index represents no of binaary strings of length i ending with 0
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    for(int i=0;i<N;i++)
    {
        ones[i]=0;
        zeros[i]=0;
    }   
    int n;
    cin>>n;
    ones[0]=0;
    ones[1]=1;
    zeros[0]=0;
    zeros[1]=1;
    for(int i=2;i<=n;i++)
    {
        ones[i]=zeros[i-1];
        zeros[i]=ones[i-1]+zeros[i-1];
    }
    cout<<ones[n]+zeros[n];
    return 0;
}