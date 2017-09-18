#include "header.h"
#include <bits/stdc++.h>


using namespace std;


table arr[MAXSIZE];
int available[MAXSIZE];

map <string,int> Keywords;
map <string,int> M;

void clearall(int in){
    arr[in].V1.clear();
    arr[in].V2.clear();
    arr[in].attr.clear();
    arr[in].actualattr.clear();
    arr[in].names.clear();
}

void initialize(){
    Keywords["int"]=1;
    Keywords["string"]=1;
}

string func(string s,int &a){
    string ans="";

    while(a<s.length() && s[a]!=' '){
        ans=ans + s[a++];
    }
    if(s[a]==' ')a++;
    return ans;
}


int if_integer(string s){
	int x=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9' ){
			x=x*10 + s[i]-'0';
		}
		else{
			return ERROR;
		}
	}
	return x;
}

string IntToString(int a){
	string s="";
	if(a==0)return "0";

	while(a!=0){
		int k=a%10;
		char x=k+'0';
		s=x+s;
		a=a/10;
	}
	return s;
}

bool isContained(string st, string arr[], int size)
{
	int i;

	for(i=0;i<size;i++)
	{
		if(st.compare(arr[i]) == 0)									// Comparing element by element
		{
			return true;
		}
	}

	return false;
}

int isContained_2(string st, string arr[], int size)
{
	int i;

	for(i=0;i<size;i++)
	{
		if(st.compare(arr[i]) == 0)									// Comparing element by element
		{
			return i;
		}
	}

	return -1;
}

void string_to_chararr(string st, char* str)
{
	unsigned int i;

	for(i=0;i<st.length();i++)
	{
		str[i] = st[i];
	}

	str[i] = '\0';
}

bool isNumeric(char* st)
{
	unsigned int i;
	int a;

	for(i=0;i<strlen(st);i++)
	{
		a = st[i];

		if(a<48 || a>57)
			return false;
	}

	return true;
}

int select_str_op(string postfix, string field_name[], string field_type[], string record[], int size)
{
	stack<string> S;

	unsigned int i;

	string temp = "";

	int pos1 = -1, pos2 = -1;

	for(i=0;i<postfix.length();i++)
	{
		if(postfix[i] != ':')
			temp += postfix[i];
		else
		{
			if(temp.compare(">") * temp.compare("<") * temp.compare("=") * temp.compare("!") * temp.compare("/") * temp.compare("\\") == 0)
			{
				if(S.size() < 2){
					//cout << "herebitch";
					return -1;

				}

				string op2 = S.top();
				S.pop();
				string op1 = S.top();
				S.pop();

				if(op1.compare("@") * op1.compare("#") == 0)
					return -1;
				if(op2.compare("@") * op2.compare("#") == 0)
					return -1;

				if(op1[0] == '"' && op1[op1.length()-1] == '"')
				{
					op1 = op1.substr(1, op1.length()-2);
				}
				else
				{
					pos1 = isContained_2(op1, field_name, size);

					//cout << op1 << " " << pos1 << " ";
					if(pos1 == -1)
						return -1;

					op1 = record[pos1];
				}

				//cout << "here ";

				if(op2[0] == '"' && op2[op2.length()-1] == '"')
				{
					op2 = op2.substr(1, op2.length()-2);
				}
				else
				{

					pos2 = isContained_2(op2, field_name, size);
				//	cout << op2 << " " << pos2 << " ";
					if(pos2 == -1)
						return -1;

					op2 = record[pos2];
				}

				//cout << "here";

				if(pos1 != -1 && pos2 != -1)
				{
					if(field_type[pos1].compare(field_type[pos2]) != 0)
						return -1;
				}

				if((pos1 != -1 && field_type[pos1].compare("int") == 0) || (pos2 != -1 && field_type[pos2].compare("int") == 0))
				{
					char op1_char[1024];
					char op2_char[1024];

					string_to_chararr(op1, op1_char);
					string_to_chararr(op2, op2_char);

					if(!isNumeric(op1_char) || !isNumeric(op2_char))
					{
						return -1;
					}

					int op1_int = atoi(op1_char);
					int op2_int = atoi(op2_char);

					if(temp.compare(">") == 0)
					{
						if(op1_int > op2_int)
							S.push("@");
						else
							S.push("#");
					}
					else if(temp.compare("<") == 0)
					{
						if(op1_int < op2_int)
							S.push("@");
						else
							S.push("#");
					}
					else if(temp.compare("=") == 0)
					{
						if(op1_int == op2_int)
							S.push("@");
						else
							S.push("#");
					}
					else if(temp.compare("!") == 0)
					{
						if(op1_int != op2_int)
							S.push("@");
						else
							S.push("#");
					}
					else if(temp.compare("/") == 0)
					{
						if(op1_int >= op2_int)
							S.push("@");
						else
							S.push("#");
					}
					else
					{
						if(op1_int <= op2_int)
							S.push("@");
						else
							S.push("#");
					}

				}
				else
				{
					if(temp.compare(">") == 0)
					{
						if(op1.compare(op2) > 0)
							S.push("@");
						else
							S.push("#");
					}
					else if(temp.compare("<") == 0)
					{
						if(op1.compare(op2) < 0)
							S.push("@");
						else
							S.push("#");
					}
					else if(temp.compare("=") == 0)
					{
						if(op1.compare(op2) == 0)
							S.push("@");
						else
							S.push("#");
					}
					else if(temp.compare("!") == 0)
					{
						if(op1.compare(op2) != 0)
							S.push("@");
						else
							S.push("#");
					}
					else if(temp.compare("/") == 0)
					{
						if(op1.compare(op2) >= 0)
							S.push("@");
						else
							S.push("#");
					}
					else
					{
						if(op1.compare(op2) <= 0)
							S.push("@");
						else
							S.push("#");
					}
				}

			}
			else if(temp.compare("&") * temp.compare("|") == 0)
			{
				if(S.size() < 2)
					return -1;

				string op2 = S.top();
				S.pop();
				string op1 = S.top();
				S.pop();

				if(op1.compare("@") * op1.compare("#") != 0)
					return -1;
				if(op2.compare("@") * op2.compare("#") != 0)
					return -1;

				bool b1, b2;

				if(op1.compare("@") == 0)
					b1 = true;
				else
					b1 = false;

				if(op2.compare("@") == 0)
					b2 = true;
				else
					b2 = false;

				if(temp.compare("&") == 0)
				{
					string to_insert;

					if(b1 & b2)
						to_insert = "@";
					else
						to_insert = "#";

					S.push(to_insert);
				}
				else
				{
					string to_insert;

					if(b1 | b2)
						to_insert = "@";
					else
						to_insert = "#";

					S.push(to_insert);
				}

			}
			else
			{
				//cout << temp << endl;
				S.push(temp);
			}

			temp = "";
		}
	}

	if(S.size() != 1)
		return -1;

	if((S.top()).compare("@") == 0)
		return 1;
	else
		return 0;
}




