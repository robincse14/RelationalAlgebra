#include "header.h"


bool error_create(string s,int &a){

	string temp=func(s,a);
	if(temp!="create"){
	    cout << "Syntax error near create\n";
	    return true;
	}

	temp=func(s,a);
	if(temp!="table"){
	    cout << "Syntax error near table\n";
	    return true;
	}

	return false;
}


int CheckAvailability(){
	for(int i=0;i<MAXSIZE;i++){
		if(available[i]==0)
			return i;
	}
	return -1;
}

void create(string s,string tablename){
	int num=CheckAvailability();
    int a=0;
    string temp="";

    if(error_create(s,a)){
    	return;
    }

    int flag=0;
    int num_int=0,num_string=0,actual=0;
    string prevname;
    while(a<s.length()){
        temp=func(s,a);
        if(flag==0){
            if(Keywords.find(temp)!=Keywords.end()){
                cout << "name of attribute should not match datatype\n";
                clearall(num);
                return;
            }
            prevname=temp;
        }
        else{
            if(Keywords.find(temp)==Keywords.end()){
                cout << "datatype not found for " << prevname << endl;
                clearall(num);
                return;
            }

            if(temp=="int"){
                arr[num].attr[prevname]=make_pair(1,num_int++);
                arr[num].names.push_back(prevname);
                arr[num].actualattr[prevname]=actual++;

            }
            else{
                arr[num].attr[prevname]=make_pair(0,num_string++);
                arr[num].names.push_back(prevname);
                arr[num].actualattr[prevname]=actual++;
            }
        }
        flag=!flag;
    }
    if(flag==1){
    	clearall(num);
    	cout << "datatype not specified\n";
    	return ;
    }
    M[tablename]=num;
    arr[num].tuples=0;
    available[num]=1;
    for(int i=0;i<100;i++){
    	vector <int> a1;
    	vector <string> b1;

    	arr[num].V1.push_back(b1);
    	arr[num].V2.push_back(a1);
    }



    cout << "Table created\n";
    return;
}

