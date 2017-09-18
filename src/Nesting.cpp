#include "header.h"

string ClosingParanthesis(string s,int &a){
	string ans="";
	int cnt=1;
	while(a<s.length()){
		if(s[a]==')'){
			cnt--;
			if(cnt==0){
				a+=2;
				return ans;
			}
		}
		else if(s[a]=='(')cnt++;

		ans+=s[a];
		a++;
	}
	return ans;
}

table Parse(string s,table &ans){
	// Stores the answer
	string temp;
	int a=0;

	temp=func(s,a);

	if(temp=="select"){
		ans=select(s.substr(a,s.length()-a),ans);
		return ans;
	}
	else if(temp=="project"){
		cout << "Calling Project \n";
		ans=project(s.substr(a,s.length()-a),ans);
		return ans;
	}
	else if(temp=="union"){
		ans=UnionMain(s.substr(a,s.length()-a),ans);
		return ans;
	}
	else if(temp=="minus"){
		ans=MinusMain(s.substr(a,s.length()-a),ans);
		return ans;
	}
	else if(temp=="product"){
		ans=ProductMain(s.substr(a,s.length()-a),ans);
		return ans;
	}
	else if(temp=="rename"){
		//ans=RenameMain(s.substr(a,s.length()-a),ans);
		return ans;
	}
	else{
		cout << temp << endl;
		cout << "Error in the Syntax\n";
		return ans;
	}
}

