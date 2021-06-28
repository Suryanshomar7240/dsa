#include <bits/stdc++.h>
using namespace std;
int prec(char c)
{
	if (c == '(')
	{
		return 0;
	}
	else if (c == '+' || c == '-')
	{
		return 1;
	}
	else if (c == '*' || c == '/')
	{
		return 2;
	}
	else
	{
		return 3;
	}
}
void inttopost(string s)
{
	string res = "";
	stack<char> st;
	//cout<<s.length();
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			res += s[i];
		}
		else if (s[i] == '(')
		{
			st.push(s[i]);
		}
		else if (s[i] == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				res += st.top();
				st.pop();
			}
			if (!st.empty())
			{
			st.pop();
			}
		}
		else
		{
			while (!st.empty() && prec(s[i]) <= prec(st.top()))
			{
				res += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while (!st.empty())
	{
		res += st.top();
		st.pop();
	}
	return s;
}
string reverse(string s)
{
	for(int i=0;i<s.length()/2;i++)
	{
		char c=s[i];
		s[i]=s[s.length()-i];
		s[s.length()-i]=s[i];
		if(s[i]=='(')
			s[i]=')';
		if(s[i]==')')
			s[i]='(';	
	}
	return s;
}
string inttopre(string s)
{
	s=reverse(s);
	s=inttopost(s);
	s=reverse(s);
	return s;
}
int main()
{
	cout<<inttopre("(a-b/c)*(l+k^d)");
	return 0;
}