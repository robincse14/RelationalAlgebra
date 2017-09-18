#include "header.h"


bool error_select(string s,int &a){

	string temp;
	temp=func(s,a);
	if(temp!="from"){
		cout << "Syntax error near select\n";
		return true;
	}

	return false;
}

table select(string s,table &X){
	int a=0; string temp;
	if(error_select(s,a))return X;

	vector <string> Y;
	temp=func(s,a);

	int flag=0;
	table input;

	if(temp=="("){
		string yy=ClosingParanthesis(s,a);
		//cout << yy << endl;
		input=Parse(yy,input);
		flag=1;
	}
	else if(M.find(temp)==M.end()){
		cout << "table does not exist\n";
		return X;
	}

	if(!flag)input=arr[M[temp]];

	temp=func(s,a);

	//cout << "here" << " " << temp << endl;
	map <string,int> localmap;
	while(temp!="where"){
		Y.push_back(temp);
		localmap[temp]=1;
		temp=func(s,a);
	}

	CreateTableNames(X,Y);
	CreateMapping(X,Y,input.attr);


	string ss="";
	for(int i=a;i<s.length();i++){
		ss+=s[i];
	}

	string post_fix=convert_to_postfix(ss);

	//cout << post_fix << endl;
	int len=input.names.size();
	string field_name[len],field_type[len],record[len];

	for(int i=0;i<len;i++){
		field_name[i]=input.names[i];
		field_type[i]=(input.attr[field_name[i]].first==1)?"int":"string";

	}

	int true_tuples=0;
	// Printing query for select
	for(int i=0;i<input.tuples;i++){

		for(int j=0;j<len;j++){
			if(field_type[j]=="int"){
				int k1=input.attr[field_name[j]].second;
				char intStr[100];
				itoa(input.V2[i][k1],intStr,10);
				record[j]= string(intStr);
			}
			else{
				int k1=input.attr[field_name[j]].second;
				record[j]=input.V1[i][k1];
			}
			//cout << record[j] << " ";
		}
		int y= select_str_op(post_fix,field_name,field_type,record,len);
		//cout << y << endl;
		if(y==-1){
			cout << "Error in query\n";
			return X;
		}
		else if(y==1){
			CreateRowTable(X,true_tuples++,input,i);
		}

	}
	X.tuples=true_tuples;
	//PrintTable(X);

	return X;
}

