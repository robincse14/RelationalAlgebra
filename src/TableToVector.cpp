#include "header.h"

void AddEmpty(vector < vector <string> > &V){
	vector <string> V1;
	V.push_back(V1);
}


void AddNames(table &X,vector < vector <string> > &V){	// Add names from table to vector
	// Push empty vector

	AddEmpty(V);

	for(int i=0;i<X.names.size();i++){
		V[0].push_back(X.names[i]);
	}
	return;
}

void AddRow(table &X,vector < vector <string> > &V,int index){	// Adding row of the (index)tuple
	AddEmpty(V);

	int len=X.names.size();

	for(int i=0;i<len;i++){
		int type=X.attr[X.names[i]].first;
		int k=X.attr[X.names[i]].second;

		if(type==1){
			string yy=IntToString(X.V2[index][k]);
			V[index+1].push_back(yy);
		}
		else{
			string yy=X.V1[index][k];
			V[index+1].push_back(yy);
		}


	}
	return;
}

void TableToVector(table &X,vector < vector <string> > &V){		// Add tuples in V from table X

	// Adding names of row
	AddNames(X,V);

	for(int i=0;i<X.tuples;i++){
		AddRow(X,V,i);
	}
	return;
}


