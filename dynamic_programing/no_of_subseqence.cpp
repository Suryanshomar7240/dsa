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
//  we have to number of subcequence of 'abc'from a string
// we have given a string where there may be some '?'  we can replace
// this'?' with a,b,c to form subsequence
//*******************************************************
//                      MAIN
//*******************************************************
int main()
{
    string s;
    cin>>s;
    int e=1,a=0,ab=0,abc=0;
    //e=represent all subsequence
    //a=no of subsequence of a
    //ab=no of subsequence of ab
    //aabc=no of subsequence of abc
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='c')
            abc+=ab;
            
        if(s[i]=='b')
            ab+=a;
        if(s[i]=='a')
            a+=e;
        if(s[i]=='?')
        {
            abc=3*abc+ab;
            ab=3*ab+a;
            a=3*a+e;
        }
    }
    cout<<abc;
    return 0;
}