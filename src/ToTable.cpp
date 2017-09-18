#include "header.h"



void CreateTableNames(table &X,vector <string> &Y){
	int xx=0;

	for(int i=0;i<Y.size();i++){
		X.names.push_back(Y[i]);
		//cout << Y[i] << " ";
		X.actualattr[Y[i]]=xx++;
	}
	//cout << endl;

}


void CreateMapping(table &X,vector <string> &Y,map <string , pair<int,int> > &Z){

	int int_type=0,string_type=0;

	for(int i=0;i<Y.size();i++){
		if(Z[Y[i]].first==1){
			X.attr[Y[i]].first=1;
			X.attr[Y[i]].second=int_type++;
		}
		else{
			X.attr[Y[i]].first=0;
			X.attr[Y[i]].second=string_type++;
		}
	}
}

void CreateRowTable(table &X,int in1,table &Y,int in2){

	// Add empty vectors
	vector <int> empty1;
	vector <string> empty2;

	X.V2.push_back(empty1);
	X.V1.push_back(empty2);
	//cout << X.names.size() << endl;

	for(int xx=0;xx<X.names.size();xx++){
	//	cout << X.names[xx] << " ";
		int k=X.attr[X.names[xx]].second;
		int k2=Y.attr[X.names[xx]].second;
		if(Y.attr[X.names[xx]].first==1){
			X.V2[in1].push_back(Y.V2[in2][k2]);
		}
		else{
			X.V1[in1].push_back(Y.V1[in2][k2]);
		}

	}
	//cout << endl;
}


void PrintTable(table &X){

	for(int i=0;i<X.names.size();i++){
		cout << X.names[i] << "\t";
	}

	cout << endl;
	for(int i=0;i<X.tuples;i++){


		for(int xx=0;xx<X.names.size();xx++){
				int in1=X.attr[X.names[xx]].second;
				int in2=X.attr[X.names[xx]].first;
				if(in2==0){
					cout << X.V1[i][in1] << "\t";

				}
				else{
					cout << X.V2[i][in1] << "\t";
				}

		}
		cout << endl;
	}

}
