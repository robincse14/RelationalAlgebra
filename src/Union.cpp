#include "header.h"


bool UnionError(table &A,table &B){
	if(A.names.size()!=B.names.size()){
		return true;
	}

	for(int i=0;i<A.names.size();i++){
		if(A.attr[A.names[i]].first!=B.attr[B.names[i]].first){
			return true;
		}
	}
	return false;
}


table Union(table &AA,table &BB,table &X){
	table A=AA,B=BB;

	if(UnionError(A,B)){
		cout << "Compatibility Not Found\n";;
		return X;
	}
	int k1=A.tuples,k2=B.tuples;
	int trace1[k1],trace2[k2];
	memset(trace1,0,sizeof(trace1));
	memset(trace2,0,sizeof(trace2));

	RemoveDuplicatesTable(A,trace1);
	RemoveDuplicatesTable(B,trace2);

	for(int i=0;i<A.tuples;i++){
		if(trace1[i]==0){
			for(int j=0;j<B.tuples;j++){
				if(CheckSame(A,i,B,j))trace2[j]=1;
			}
		}
	}
	int num_rows=0;

	CreateTableNames(X,A.names);

	CreateMapping(X,A.names,A.attr);

	for(int i=0;i<A.tuples;i++){
		if(trace1[i]==0)
			CreateRowTable(X,num_rows++,A,i);
	}

	for(int j=0;j<B.tuples;j++){
		if(trace2[j]==0)
			CreateRowTable(X,num_rows++,B,j);
	}

	X.tuples=num_rows;
	//PrintTable(X);

	return X;
}



bool CheckSame(table &A,int in1,table &B,int in2){

	for(int i=0;i<A.names.size();i++){
		int k1=A.attr[A.names[i]].second;
		int k2=B.attr[B.names[i]].second;
		if(A.attr[A.names[i]].first==1){
			if(A.V2[in1][k1]!=B.V2[in2][k2])return false;
		}
		else{
			if(A.V1[in1][k1]!=B.V1[in2][k2])return false;
		}
	}
	return true;
}

void RemoveDuplicatesTable(table &A,int trace[]){
	for(int i=0;i<A.tuples;i++){
		if(trace[i]==0){
			for(int j=i+1;j<A.tuples;j++){
				if(CheckSame(A,i,A,j))trace[j]=1;
			}
		}
	}
}

table UnionMain(string s,table &X){
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


	/*cout << "Printing input1 Union\n";
	PrintTable(input1);
	cout << "Printing input2 Union\n ";
	PrintTable(input2);*/
	return Union(input1,input2,X);


}
