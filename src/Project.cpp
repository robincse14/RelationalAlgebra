#include "header.h"

using namespace std;


bool error_project(string s, int &a){
	string temp;
	temp=func(s,a);
	cout << temp << endl;

	cout << "I am here\n";
	if(temp!="from"){
		cout << "error near from\n";
		return true;
	}
	return false;
}

table project(string s,table &X){
	//cout << s << endl;
	int a=0; string temp;

	vector <string> Y;

	/*if(error_project(s,a)){
		return X;
	}*/
	//cout << "Yobabes\n";
	temp=func(s,a);
	temp=func(s,a);
	cout << temp << endl;
	table input;int flag=0;
	if(temp=="("){
		string yy=ClosingParanthesis(s,a);
		//cout << yy << endl;
		input=Parse(yy,input);
		//cout << "Input Recieved\n";
		flag=1;
	}
	else if(M.find(temp)==M.end()){
		cout <<"table does not exist";
		return X;
	}
	cout << "here\n";
	int y=a;

	if(!flag)input=arr[M[temp]];

	if(!checkerror(s,y,input)){
		cout << "attributes does not exist\n";
		return X;
	}

	map <string,int> selected;

	while(a<s.length()){
		temp=func(s,a);
		cout << temp << " ";
		Y.push_back(temp);
		selected[temp]=1;
	}

	CreateTableNames(X,Y);
	CreateMapping(X,Y,input.attr);


	Printing(input,selected,X,Y);

	return X;
}

void Printing(table &A,map<string,int> &selected,table &X,vector <string> &Y){

	for(int i=0;i<A.tuples;i++){

		CreateRowTable(X,i,A,i);
	}

	X.tuples=A.tuples;
	//PrintTable(X);
}

bool checkerror(string s,int y,table M1){

	while(y<s.length()){
		string temp=func(s,y);
		if(M1.attr.find(temp)==M1.attr.end()){
			cout << temp << "Not Found\n" << endl;
			return false;
		}
	}
	return true;
}


