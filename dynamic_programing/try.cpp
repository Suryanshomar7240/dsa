#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> s, s2;
        s.push("/");
        while (path.length() > 0)
        {
            // while (path[0] == '.' && path[1] == '.')
            // {
            //     if (s.size() > 1)
            //         s.pop();
            //     path = path.substr(2);
            //     if (path[0] == '/')
            //     {
            //         path = path.substr(1);
            //     }
            // }
            // while (path.length() > 0 && (path[0] == '/' || path[0] == '.'))
            // {
            //     if (path[0] == '.' && path[1] == '.')
            //         break;
            //     path = path.substr(1);
            // }
            while (path.length() > 0 && path[0] == '/')
            {
                path = path.substr(1);
            }
            string temp = "";
            while (path.length() > 0 && path[0] != '/')
            {
                temp += path[0];
                path = path.substr(1);
            }
            if(temp=="..")
            {
                if(s.size()>1)
                    s.pop();
            }
            else if(temp==".");
            else if(temp.length()!=0)
                s.push(temp);
        }

        string ans = "";
        while (!s.empty())
        {
            s2.push(s.top());
            s.pop();
        }
        s2.pop();
        while (!s2.empty())
        {
            ans += "/";
            ans += s2.top();
            s2.pop();
        }
        if (ans.length() == 0)
            return "/";
        return ans;
    }
};
int main()
{
    Solution s;
    cout << s.simplifyPath("/a//b////c/d//././/..");
    return 0;
}