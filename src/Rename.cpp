#include "header.h"




table Rename(table &A,string s2,table &X){

	X=A;
	//PrintTable(A);
	//cout << "X\n";
	//PrintTable(X);
	X.attr.clear();
	X.names.clear();
	for(int i=0;i<A.names.size();i++){
		X.names.push_back(s2+"."+A.names[i]);
		X.attr[X.names[i]].first=A.attr[A.names[i]].first;
		X.attr[X.names[i]].second=A.attr[A.names[i]].second;

	}


	return X;
}

table RenameMain(string s,table &X){
	int a=0;
	string temp=func(s,a);
	table input;
	if(temp=="("){
		string yy=ClosingParanthesis(s,a);
		input=Parse(yy,input);

	}
	else{
		input=arr[M[temp]];
	}
	// Exclude comma
	temp=func(s,a);

	temp=func(s,a);

	return Rename(input,temp,X);
}


