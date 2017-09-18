#include "header.h"

void PrintRow(string table,int row_index){
	int in1=M[table],k1=row_index;

	int len=arr[in1].names.size();

	for(int i=0;i<len;i++){
		if(arr[in1].attr[arr[in1].names[i]].first==1){
			int V_index=arr[in1].attr[arr[in1].names[i]].second;

			cout << arr[in1].V2[k1][V_index] << "\t";

		}
		else{
			int V_index=arr[in1].attr[arr[in1].names[i]].second;

			cout << arr[in1].V1[k1][V_index] << "\t";
		}
	}
}

