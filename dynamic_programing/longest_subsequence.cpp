#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
int dp[N];
//memoization method
int lis(vector<int> &arr, int n)
{
    if (dp[n] != -1)
        return dp[n];
    dp[n] = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[n] > arr[i])
            dp[n] = max(dp[n], 1 + lis(arr, i));
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans=0;

    // tabulation method
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
                dp[i]=max(dp[i],1+dp[j]);
        }
        ans=max(dp[i],ans);
    }
    cout<<ans;
    // cout << lis(arr, n - 1);

}