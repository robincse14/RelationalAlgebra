#include "header.h"

void PrintVector(vector <vector <string> > &s1,int size){


	for(int i=0;i<size;i++){
		for(int j=0;j<s1[i].size();j++){
			cout << s1[i][j] << "\t";
		}
		cout << endl;
	}
}

void PrintVector(vector <vector <string> > &s1,int trace[],int size){

	for(int i=0;i<size;i++){
		if(trace[i]==0){
			for(int j=0;j<s1[i].size();j++){
				cout << s1[i][j] << "\t";
			}
			cout << endl;
		}
	}
}
