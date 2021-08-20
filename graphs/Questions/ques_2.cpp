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
//tree prsent containing 3 colors A,B,C
//find number of edeges such that
//*******************************************************

//recursive function
bool checker(string str, vector<vector<char>> arr, int i, int j)
{
    // cout<<str[0]<<endl;
    if (str.length() == 1)
        return true;
    char c = arr[i][j];
    if (j != 0 && arr[i][j - 1] != '$')
    {
        if (arr[i][j - 1] = str[1])
        {
            arr[i][j] = '$';
            if (checker(str.substr(1), arr, i, j - 1))
                return true;
            else
                arr[i][j] = c;
        }
    }
    if (i != 0 && arr[i - 1][j] != '$')
    {
        if (arr[i - 1][j] = str[1])
        {
            arr[i][j] = '$';
            if (checker(str.substr(1), arr, i - 1, j))
                return true;
            else
                arr[i][j] = c;
        }
    }
    if (j < arr[i].size() && arr[i][j + 1] != '$')
    {
        if (arr[i][j + 1] = str[1])
        {
            arr[i][j] = '$';
            if (checker(str.substr(1), arr, i, j + 1))
                return true;
            else
                arr[i][j] = c;
        }
    }
    if (i < arr.size() && arr[i + 1][j] != '$')
    {
        if (arr[i + 1][j] = str[1])
        {
            arr[i][j] = '$';
            if (checker(str.substr(1), arr, i + 1, j))
                return true;
            else
                arr[i][j] = c;
        }
    }
    return false;
}

//*******************************************************
//                      MAIN
//*******************************************************

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n);
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            char c;
            cin >> c;
            arr[i].push_back(c);
        }
    }
    string str;
    cin >> str;
    vector<pair<int, int>> start_char;
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cout << arr[i][j] << " ";
            if (arr[i][j] == (char)str[0])
            {
                start_char.push_back(make_pair(i, j));
            }
        }
        cout << endl;
    }
    bool found = false;
    for (auto i : start_char)
    {
        if (checker(str, arr, i.first, i.second))
        {
            found = true;
            break;
        }
    }
    if(found)
        cout<<"Word is present";
    else
        cout<<"word is not present";
    return 0;
}