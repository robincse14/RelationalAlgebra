#include "header.h"

bool isHigher(char a, char b)
{
	if(b == '(')
		return true;

	if((a == '&' && b == '|') || (a == '|' && b == '&'))
	{
		return false;
	}

	if(b == '&' || b == '|')
		return true;

	return false;
}


string convert_to_postfix(string stmt)
{
	string st = "";

	unsigned int i;

	for(i=0;i<stmt.length();i++)
	{
		if(stmt[i] != ' ')
			st += stmt[i];
	}

	st += " ";

	string res = "";

	string temp = "";

	stack<char> S;

	for(i=0;i<st.length();i++)
	{
		if(st[i] != '>' && st[i] != '<' && st[i] != '=' && st[i] != '!' && st[i] != '&' && st[i] != '|' && st[i] != ' ' && st[i] != '(' && st[i] != ')')
			temp += st[i];
		else
		{
			res += temp;
			res += ":";
			temp = "";

			if(st[i] == '(')
			{
				S.push(st[i]);
				continue;
			}

			if(st[i] == ')')
			{
				while(!S.empty() && S.top()!='(')
				{
					res += S.top();
					res += ":";
					S.pop();
				}

				if(S.empty())
					return "Invalid syntax";

				S.pop();

				continue;
			}

			if(st[i] != ' ')
			{
				while(!S.empty() && !isHigher(st[i], S.top()))
				{
					res += S.top();
					res += ":";
					S.pop();
				}

				if((st[i] == '<' || st[i] == '>') && (i < st.length()-1) && (st[i+1] == '='))
				{
					if(st[i] == '<')
						S.push('\\');
					else
						S.push('/');

					i++;
				}
				else
				{
					S.push(st[i]);
				}
			}
		}
	}

	while(!S.empty())
	{
		if(S.top() == '(')
			return "Invalid Syntax";

		res += S.top();
		res += ":";
		S.pop();
	}

	string ans = "";

	for(i=0;i<res.length();i++)
	{
		if(res[i] == ':' && ans[ans.length()-1] == ':')
			continue;

		if(ans != "" || (ans == "" && res[i] != ':'))
			ans += res[i];
	}

	return ans;

}
