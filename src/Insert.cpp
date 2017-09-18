#include "header.h"

bool error_insert(string s,int &a){

	string temp=func(s,a);
	if(temp!="insert"){
		cout << "error near insert\n";
		return true;
	}

	temp=func(s,a);
	if(temp!="into"){
		cout << "error near into\n";
		return true;
	}
	return false;
}

void insert(string s){
	int a=0;
	string temp="";
	if(error_insert(s,a))return;

	temp=func(s,a);
	if(M.find(temp)==M.end()){
		cout << "table does not exist\n";
		return;
	}

	int k=M[temp];

	int xx=0;
	int index=arr[k].tuples;

	while(a<s.length()){
		temp=func(s,a);
		//cout << temp << " " << xx << endl;
		if(xx>=arr[k].names.size()){
			cout << "Number of values don't match\n";
			return;
		}


		if(arr[k].attr[arr[k].names[xx]].first==0){
			arr[k].V1[index].push_back(temp);
		}
		else{
			int yy=if_integer(temp);
			if(yy==-1){
				cout << "Data type of values does not match the corresponding data type\n";
				arr[k].V1[index].clear();
				arr[k].V2[index].clear();
				return;
			}
			arr[k].V2[index].push_back(yy);
		}
		xx++;

	}

	if(xx!=arr[k].names.size()){
		cout << "Less number of values given\n";
		arr[k].V1[index].clear();
		arr[k].V2[index].clear();
		return;
	}
	arr[k].tuples++;

	cout << "Row inserted\n";

	return;
}

