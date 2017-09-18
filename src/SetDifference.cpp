#include "header.h"


table SetDifference(table &AA,table &BB,table &X){
	table A=AA,B=BB;

	if(UnionError(A,B)){
		cout << "Compatibility Not Found\n";
		return X;
	}

	int k1=A.tuples,k2=B.tuples;

	int trace1[k1],trace2[k2];

	memset(trace1,0,sizeof(trace1));
	memset(trace2,0,sizeof(trace2));

	RemoveDuplicatesTable(A,trace1);
	RemoveDuplicatesTable(B,trace2);

	for(int i=0;i<k1;i++){
		if(trace1[i]==0){
			for(int j=0;j<k2;j++){
				if(CheckSame(A,i,B,j))trace1[i]=1;
			}
		}
	}

	CreateTableNames(X,A.names);

	CreateMapping(X,A.names,A.attr);
	int num_rows=0;
	for(int i=0;i<k1;i++){
		if(trace1[i]==0){
			CreateRowTable(X,num_rows++,A,i);
		}
	}
	X.tuples=num_rows;

	//PrintTable(X);
	return X;
}

table MinusMain(string s,table &X){
	int a=0;
	string temp=func(s,a);
	table input1,input2;

	if(temp=="("){
		string yy=ClosingParanthesis(s,a);
		input1=Parse(yy,input1);
	}
	else{
		input1=arr[M[temp]];
	}
	// Exclude "comma"

	temp=func(s,a);
	//cout << temp << endl;
	temp=func(s,a);
	//cout << temp << endl;
	if(temp=="("){
		string yy=ClosingParanthesis(s,a);
		//cout << yy << endl;
		input2=Parse(yy,input2);
	}
	else{
		input2=arr[M[temp]];
	}


	//cout << "Printing input1\n";
	//PrintTable(input1);
	//cout << "Printing input2\n";
	//PrintTable(input2);
	return SetDifference(input1,input2,X);

}
