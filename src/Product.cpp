#include "header.h"



table CartesianProduct(table &A,table &B,table &X){
	// Add Names and Map
	int int_index=0,string_index=0;
	for(int i=0;i<A.names.size();i++){
		X.names.push_back("A."+A.names[i]);
		if(A.attr[A.names[i]].first==1){
			X.attr[X.names[i]].first=1;
			X.attr[X.names[i]].second=int_index++;
		}
		else{
			X.attr[X.names[i]].first=0;
			X.attr[X.names[i]].second=string_index++;
		}
	}
	for(int i=0;i<B.names.size();i++){
		X.names.push_back("B."+B.names[i]);
		if(B.attr[B.names[i]].first==1){
			X.attr[X.names[i+A.names.size()]].first=1;
			X.attr[X.names[i+A.names.size()]].second=int_index++;
		}
		else{
			X.attr[X.names[i+A.names.size()]].first=0;
			X.attr[X.names[i+A.names.size()]].second=string_index++;
		}
	}


	for(int i=0;i<A.tuples;i++){
		CartesianProductUtil(A,i,B,X);
	}

	X.tuples=A.tuples*B.tuples;

	//PrintTable(X);

	return X;

}


void CartesianProductUtil(table &A,int row_index,table &B,table &X){

	for(int i=0;i<B.tuples;i++){
		vector <int> empty1;
		vector <string> empty2;

		X.V1.push_back(empty2);
		X.V2.push_back(empty1);

		AddRowTable(X,row_index*B.tuples+i,A,row_index);
		AddRowTable(X,row_index*B.tuples+i,B,i);
	}
}

void AddRowTable(table &A,int in1,table &B,int in2){

	int len=B.names.size();

	for(int i=0;i<len;i++){
	    int k=B.attr[B.names[i]].second;
		if(B.attr[B.names[i]].first==1){
			A.V2[in1].push_back(B.V2[in2][k]);
		}
		else{
			A.V1[in1].push_back(B.V1[in2][k]);
		}
	}
	return;


}

table ProductMain(string s,table &X){
	int a=0;
	string temp=func(s,a);
	table input1,input2;

	if(temp=="("){
		string yy=ClosingParanthesis(s,a);
		//cout << yy << "Product string\n";
		input1=Parse(yy,input1);
	}
	else{
		input1=arr[M[temp]];
	}
	// Exclude "comma"

	temp=func(s,a);
	//cout << temp << endl;
	/*for(int i=a;i<s.length();i++){
				cout << s[i];
			}
	cout << "yobaby";
			cout << endl;
	//cout << temp << endl;*/
	temp=func(s,a);

	//cout << temp << endl;
	if(temp=="("){
		string yy=ClosingParanthesis(s,a);
		//cout << yy << "string2Product\n";
		input2=Parse(yy,input2);
	}
	else{
		input2=arr[M[temp]];
	}


	/*cout << "Printing input1 Product\n\n\n\n\n";
	PrintTable(input1);
	cout << "Printing input2 Product\n";
	PrintTable(input2);*/
	return CartesianProduct(input1,input2,X);

}
